package com.harshraj22;


// A mock database connection class
class Connection {
    private final long id = (long) (Math.random() * 1000);
    public void beginTransaction() { System.out.println("T-" + id + ": Connection BEGIN"); }
    public void commit() { System.out.println("T-" + id + ": Connection COMMIT"); }
    public void close() { System.out.println("T-" + id + ": Connection CLOSE"); }
    public String toString() { return "Connection-" + id; }
}

// A mock Persistence Context (the "staging area")
class PersistenceContext {
    private final Connection connection; // It uses the connection!
    public PersistenceContext(Connection conn) { this.connection = conn; }

    public void flush() {
        // This is where JPA would do its "dirty check" and generate SQL
        System.out.println("T-" + connection.toString() + ": JPA: Flushing changes (generating SQL)...");
    }
    public void clear() {
        // This is where the EM empties its in-memory cache
        System.out.println("T-" + connection.toString() + ": JPA: Clearing Persistence Context");
    }
}

// A mock Entity Manager that manages the Persistence Context
class EntityManager {
    private final PersistenceContext context;
    public EntityManager(Connection conn) { this.context = new PersistenceContext(conn); }
    public void flush() { this.context.flush(); }
    public void clear() { this.context.clear(); }
}

/**
 * This class now resembles Spring's AbstractPlatformTransactionManager.
 * It manages both the JDBC Connection and the JPA EntityManager
 * by binding them to the current thread.
 */
public class TransactionManager {

    // A ThreadLocal for the raw JDBC Connection
    private static ThreadLocal<Connection> currentConnection = new ThreadLocal<>();

    // A ThreadLocal for the JPA EntityManager
    private static ThreadLocal<EntityManager> currentManager = new ThreadLocal<>();

    /**
     * Used by JDBC (like JdbcTemplate)
     */
    public static Connection getConnection() {
        return currentConnection.get();
    }

    /**
     * Used by JPA (like your Repositories)
     */
    public static EntityManager getEntityManager() {
        return currentManager.get();
    }

    /**
     * This is the "magic" that happens when a @Transactional method starts.
     */
    public static void startTransaction() {
        // 1. Get a new connection from the "pool"
        Connection conn = new Connection();
        conn.beginTransaction();

        // 2. Create a new EntityManager that USES that connection
        EntityManager em = new EntityManager(conn);

        // 3. Bind BOTH resources to the current thread
        currentConnection.set(conn);
        currentManager.set(em);
        System.out.println("T-" + conn.toString() + ": Transaction START");
    }

    /**
     * This happens when the @Transactional method succeeds.
     */
    public static void commitTransaction() {
        // 1. Get the managers for this thread
        EntityManager em = currentManager.get();
        Connection conn = currentConnection.get();

        // 2. First, flush JPA to send its SQL to the connection
        if (em != null) {
            em.flush();
        }

        // 3. Second, commit the connection to finalize all work (JPA + JDBC)
        if (conn != null) {
            conn.commit();
        }
        System.out.println("T-" + (conn != null ? conn.toString() : "null") + ": Transaction COMMIT");
    }

    /**
     * This happens in the "finally" block, whether it succeeds or fails.
     */
    public static void closeTransaction() {
        // 1. Get the managers
        EntityManager em = currentManager.get();
        Connection conn = currentConnection.get();

        // 2. Clear the EntityManager and remove it from the thread
        if (em != null) {
            em.clear();
            currentManager.remove();
        }

        // 3. Close the Connection (return to pool) and remove it from the thread
        if (conn != null) {
            conn.close();
            currentConnection.remove();
        }
        System.out.println("T-" + (conn != null ? conn.toString() : "null") + ": Transaction CLOSE & CLEANUP");
    }
}