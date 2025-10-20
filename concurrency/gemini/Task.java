package com.harshraj22;

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class Task<V> extends FutureTask<V> implements Comparable<Task<V>>  {
    private int taskPriority;

    public Task(int priority, Callable<V> callable) {
        super(callable);
        this.taskPriority = priority;
    }

    @Override
    public int compareTo(Task o) {
        return this.taskPriority - o.taskPriority ;
    }
}
