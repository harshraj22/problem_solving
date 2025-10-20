package com.harshraj22;

import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicInteger;

public class MyCustomThreadFactory implements ThreadFactory {
    private final String namePrefix;
    private final AtomicInteger counter ;

    public MyCustomThreadFactory(String namePrefix) {
        this.namePrefix = namePrefix;
        this.counter = new AtomicInteger(0);
    }

    @Override
    public Thread newThread(Runnable r) {
        Thread thread = new Thread(r);
        thread.setName(namePrefix + counter.incrementAndGet());
        return thread;
    }
}
