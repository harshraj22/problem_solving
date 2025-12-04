package com.harshraj22.lock.comparision;

import java.util.concurrent.atomic.LongAdder;
import java.util.concurrent.locks.StampedLock;
import java.util.ArrayList;
import java.util.List;

public class Benchmark {

    // Shared State
    static final LongAdder totalReads = new LongAdder();
    static volatile boolean running = true;

    // The object we are testing
    private static final LockTest myLockTest = new LockTest();

    public static void main(String[] args) throws InterruptedException {
        System.out.println("--- Starting Benchmark ---");

        // 1. WARMUP PHASE (3 seconds)
        // We run this to let the JVM optimize the code (JIT), but we ignore the stats.
        runBenchmarkPhase("Warmup", 3);

        System.out.println("--------------------------");

        // 2. MEASUREMENT PHASE (5 seconds)
        // This is the real test.
        runBenchmarkPhase("Measurement", 5);
    }

    private static void runBenchmarkPhase(String phaseName, int durationSeconds) throws InterruptedException {
        System.out.println("Running " + phaseName + " Phase (" + durationSeconds + "s)...");

        // Reset state for this phase
        totalReads.reset();
        running = true;
        List<Thread> threads = new ArrayList<>();

        // Start 10 Reader Threads
        for (int i = 0; i < 10; i++) {
            Thread t = new Thread(() -> {
                while (running) {
                    myLockTest.calculateDistanceFromOrigin();
                    totalReads.increment();
                }
            });
            t.start();
            threads.add(t);
        }

        // Start 1 Writer Thread
        Thread writer = new Thread(() -> {
            while(running) {
                myLockTest.movePoint(1.0, 1.0);
                try { Thread.sleep(1); } catch (Exception e) {}
            }
        });
        writer.start();
        threads.add(writer);

        // --- THE CLOCK STARTS HERE ---
        long startTime = System.currentTimeMillis();

        // Let it run
        Thread.sleep(durationSeconds * 1000);

        // Stop everything
        running = false;
        long endTime = System.currentTimeMillis();

        // Wait for threads to actually die to ensure clean state for next phase
        for (Thread t : threads) {
            t.join();
        }

        // Calculate Results
        long count = totalReads.sum();
        double seconds = (endTime - startTime) / 1000.0;
        double throughput = count / seconds;

        // Format Output with underscores (e.g. 18_000_000)
        String formattedCount = String.format("%,d", count).replace(',', '_');
        String formattedThroughput = String.format("%,.2f", throughput).replace(',', '_');

        System.out.println("[" + phaseName + "] Total Reads: " + formattedCount);
        System.out.println("[" + phaseName + "] Throughput:  " + formattedThroughput + " reads/sec");
    }

    // Inner class implementing the StampedLock logic
    static class LockTest1 {
        /*
        * [Measurement] Total Reads: 2_863_940_466
          [Measurement] Throughput:  572_444_626.42 reads/sec
        * */
        private double x, y;
        private final StampedLock sl = new StampedLock();

        // Writer
        void movePoint(double deltaX, double deltaY) {
            long stamp = sl.writeLock();
            try {
                x += deltaX;
                y += deltaY;
            } finally {
                sl.unlockWrite(stamp);
            }
        }

        // Reader (Optimistic)
        double calculateDistanceFromOrigin() {
            long stamp = sl.tryOptimisticRead();
            double currentX = x;
            double currentY = y;

            if (!sl.validate(stamp)) {
                stamp = sl.readLock();
                try {
                    currentX = x;
                    currentY = y;
                } finally {
                    sl.unlockRead(stamp);
                }
            }
            return Math.hypot(currentX, currentY);
        }
    }
}