package com.harshraj22.lock.comparision;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class LockTest {
    private double x = 0;
    private double y = 0;
    private final ReentrantReadWriteLock lock = new ReentrantReadWriteLock();

    public void calculateDistanceFromOrigin() {
        Lock lock1 = lock.readLock();
        lock1.lock();
        Math.hypot(x, y);
        lock1.unlock();
    }

    public void movePoint(double newX, double newY) {
        Lock lock1 = lock.writeLock();
        lock1.lock();
        x += newX;
        y += newY;
        lock1.unlock();
    }
}
