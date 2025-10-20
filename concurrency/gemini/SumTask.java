package com.harshraj22;

import java.util.List;
import java.util.concurrent.ForkJoinTask;
import java.util.concurrent.RecursiveTask;

public class SumTask extends RecursiveTask<Long> {
    private final List<Integer> numbers;
    private final int startIndex;
    private final int endIndex;
    private final int THRESHOLD = 10;

    public SumTask(List<Integer> numbers, int startIndex, int endIndex) {
        this.numbers = numbers;
        this.startIndex = startIndex;
        this.endIndex = endIndex;
    }

    @Override
    protected Long compute() {
        System.out.println(Thread.currentThread().getName() + " computing for " + startIndex + " to " + endIndex);

        if (endIndex - startIndex < THRESHOLD) {
            return this.numbers.subList(startIndex, endIndex).stream().mapToLong(Long::valueOf).sum();
        }
        else {
            int middle = (startIndex + endIndex) / 2;
            SumTask leftTask = new SumTask(numbers, startIndex, middle);
            SumTask rightTask = new SumTask(numbers, middle, endIndex);

            ForkJoinTask<Long> leftTaskForked = leftTask.fork();
            Long rightTaskResult = rightTask.compute();
            return leftTaskForked.join() + rightTaskResult;
        }
    }
}
