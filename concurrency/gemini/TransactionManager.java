package com.harshraj22;

// A mock database connection class
class Connection {
    private final long id = (long) (Math.random() * 1000);
    public void beginTransaction() { System.out.println("T-" + id + ": BEGIN"); }
    public void commit() { System.out.println("T-" + id + ": COMMIT"); }
    public void close() { System.out.println("T-" + id + ": CLOSE"); }
    public String toString() { return "Connection-" + id; }
}

public class TransactionManager {
    // How do we define our ThreadLocal here?
    private static ThreadLocal<Connection> currentConnection = ThreadLocal.withInitial(() -> new Connection());

    public static Connection getConnection() {
        // How do we get the connection for this thread?
        return currentConnection.get();
    }

    public static void startTransaction() {
        // How do we create a new connection and store it?
        getConnection().beginTransaction();
    }

    public static void commitTransaction() {
        getConnection().commit();
    }

    public static void closeTransaction() {
        // How do we close and remove the connection?
        currentConnection.get().close();
        currentConnection.remove();
    }
}