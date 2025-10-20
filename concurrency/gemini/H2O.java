
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.ReentrantLock;

class H2O {
    CyclicBarrier hBarrier;
    CyclicBarrier oBarrier;
    AtomicInteger hCounter;
    ReentrantLock lock;

    public H2O() {
        hBarrier = new CyclicBarrier(2);
        oBarrier = new CyclicBarrier(1);
        hCounter = new AtomicInteger(0);
        lock = new ReentrantLock();
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        try {
            hBarrier.await();
        } catch (BrokenBarrierException e) {
            throw new RuntimeException(e);
        }
        hCounter.incrementAndGet();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();

        // the second thread should reset oBarrier
        lock.lock();
        if (hCounter.get() % 2 == 0) {
            oBarrier.reset();
        }
        lock.unlock();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        try {
            oBarrier.await();
        } catch (BrokenBarrierException e) {
            throw new RuntimeException(e);
        }

        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        hBarrier.reset();
    }
}