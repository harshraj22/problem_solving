Java Concurrency 🗺️


1. The "Workers" 🏃 (The "doers")
- Thread (Platform): The classic, heavyweight thread managed directly by the operating system.
- Runnable / Callable: Interfaces that define a "task" for a thread to run (with Callable able to return a result).
- Virtual Threads: Lightweight, JVM-managed threads that are cheap to create and ideal for I/O-bound tasks.

2. The "Managers" 🧑‍💼 (How tasks are executed)
- ExecutorService: Manages a pool of re-usable platform threads to run many independent tasks.
- ForkJoinPool: A specialized pool that uses "work-stealing" to solve large, divisible, CPU-bound problems.
- StructuredConcurrency: A modern framework that ties task lifetimes to code blocks, simplifying cleanup and error handling.

3. The "Rulebook" 📜 (Synchronization - "Don't interfere!")
- synchronized: A built-in Java keyword that provides simple, "intrinsic" locking on any object.
- Lock: A more flexible and powerful interface (like ReentrantLock) for advanced, explicit locking control.
- Atomic Variables: Provide thread-safe operations (like incrementAndGet) on a single variable without needing explicit locks.

4. The "Relay Race" 🏁 (Thread Coordination - "Wait for me!")
- Object.wait() / notify(): The low-level, fundamental way for threads to signal each other using an object's monitor.
- Semaphore: Limits the number of concurrent threads that can access a specific resource or block of code.
- CountDownLatch: A one-time "starting gate" that makes one or more threads wait until a counter reaches zero.
- CyclicBarrier: A reusable "checkpoint" where a fixed number of threads must all wait for each other to arrive before proceeding.

5. The "Backpack" 🎒 (Thread-Specific Data)
- ThreadLocal: Provides each thread with its own private, mutable copy of a variable.
- InheritableThreadLocal: A ThreadLocal variant that passes a copy of its value from a parent thread to a new child thread.
- ScopedValue: The modern, immutable replacement for ThreadLocal, which binds a value to a code scope instead of a thread.