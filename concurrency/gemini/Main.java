package com.harshraj22;

import java.time.Duration;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.concurrent.*;
import java.util.function.Function;

public class Main {
    static void main() {

    }

    static void findMaxInArray() {
        List<Integer> list = new ArrayList<>(Collections.nCopies(100, 0));
        ExecutorService executor = Executors.newFixedThreadPool(10);

        List<Future<Integer>> futures = new ArrayList<>();
        for (int i = 0; i < list.size(); i = i + 10) {
            int index = i;
            futures.add(executor.submit(() -> getMaxInArray(list, index, index+10)));
        }

        // wait for all tasks to finish
        int max = 0;
        for (Future<Integer> future : futures) {
            try {
                max = Math.max(max, future.get());
            } catch (InterruptedException | ExecutionException e) {

            }
        }

        System.out.println("Max of the array is: " + max);
    }

    static int getMaxInArray(List<Integer> list, int leftIndex, int rightIndex) {
        return Collections.max(list.subList(leftIndex, rightIndex));
    }

    static void threadLocalExample() {
        // Our 'global' map
        ThreadLocal<String> currentUser  = new ThreadLocal<>();

        // In handleRequest()
        currentUser.set("user123");

        // In logAccess()
        String userId = currentUser.get();

        // At the end of handleRequest()...
        currentUser.remove();
    }

    static void priorityBasedTaskExecution() throws InterruptedException, ExecutionException {

        ExecutorService executorService = new ThreadPoolExecutor(2, 2, 0L, TimeUnit.MILLISECONDS, new PriorityBlockingQueue<>());
        List<Task> tasks = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            Task sendNewsletter = new Task(1, () -> {
                System.out.println("Sending newsletter...");
                return "Send News letter";
            });
            tasks.add(sendNewsletter);
            executorService.execute(sendNewsletter);
        }

        for (int i = 0; i < 2; i++) {
            Task processPayment = new Task(0, () -> {
                System.out.println("Processing payment...");
                return "Process Payment";
            });
            tasks.add(processPayment);
            executorService.execute(processPayment);
        }

        executorService.shutdown();
        executorService.awaitTermination(1, TimeUnit.MINUTES);

        System.out.println("Last task was: " + tasks.getLast().get());
    }

    static void dataAggregatorUsingApisAndStructuredConcurrency() {
        try (var scope = StructuredTaskScope.open(
                StructuredTaskScope.Joiner.awaitAll(),
                cf -> cf.withTimeout(Duration.ofMillis(2_500)))
        ) {
            var apiAResponse = scope.fork(Main::fetchApiA);
            var apiBResponse = scope.fork(Main::fetchApiB);
            var apiCResponse = scope.fork(Main::fetchApiC);

            try {
                scope.join();
            } catch(StructuredTaskScope.TimeoutException e){

            }

            System.out.println("apiAResponse: " + apiAResponse.state());
            System.out.println("apiBResponse: " + apiBResponse.state());
            System.out.println("apiCResponse: " + apiCResponse.state());
        } catch (InterruptedException e) {

        }
    }

    static void dataAggregatorUsingApis() throws InterruptedException, ExecutionException, TimeoutException {
        // Data Aggregator Task
        Callable<String> apiA = Main::fetchApiA;
        Callable<String> apiB = Main::fetchApiB;
        Callable<String> apiC = Main::fetchApiC;

        ExecutorService executor = Executors.newFixedThreadPool(3);

        List<Future<String>> apiResponses= executor.invokeAll(List.of(apiA, apiB, apiC), 2_500, TimeUnit.MILLISECONDS);

        executor.shutdown();
        StringBuilder stringBuilder = new StringBuilder();

        for (Future<String> future : apiResponses) {
            switch (future.state()) {
                case SUCCESS:
                    stringBuilder.append(future.get());
                    break;
                case FAILED, CANCELLED:
                    stringBuilder.append("Task failed, ");
                    break;
            }
        }

        System.out.println(stringBuilder);
    }

    static String fetchApiA() {
        try {
            Thread.sleep(2_000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return "Fetched From Api A, ";
    }

    static String fetchApiB() {
        try {
            Thread.sleep(3_000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return "Fetched From Api B, ";
    }

    static String fetchApiC() {
        try {
            Thread.sleep(1_000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return "Fetched From Api C, ";
    }

    static void simpleWebServerWithHealthCheck() throws InterruptedException {
        ExecutorService requestHandler = Executors.newFixedThreadPool(5);
        ScheduledExecutorService healthChecker = Executors.newScheduledThreadPool(1);

        List<Future<?>> futures = new ArrayList<>();

        for (int i = 0; i < 20; i++) {
            futures.add(requestHandler.submit(Main::handleRequest));
        }

        healthChecker.scheduleWithFixedDelay(Main::checkHealth, 0, 3, TimeUnit.SECONDS);

        requestHandler.shutdown();
        requestHandler.awaitTermination(5, TimeUnit.SECONDS);

        healthChecker.shutdown();
        healthChecker.shutdownNow();
    }

    private static void handleRequest() {
        System.out.println("Processing request...");
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private static void checkHealth() {
        System.out.println("System is healthy");
    }

    static void forkJoinPoolMain() throws InterruptedException {
        List<Integer> list = new ArrayList<>(Collections.nCopies(100, 1));
        SumTask sumTask = new SumTask(list, 0, 100);

        ForkJoinPool forkJoinPool = ForkJoinPool.commonPool();
        System.out.println("Final Sum is: " + forkJoinPool.invoke(sumTask));
    }

    static void previousMain() throws InterruptedException {
        ThreadFactory threadFactory = new MyCustomThreadFactory("harsh-thread-");
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(10, threadFactory);

        for (int i = 0; i < 100; i++) {
            int index = i;
            ScheduledFuture<?> future = executor.schedule(() -> {
                System.out.println("Task " + index + " is running in " + Thread.currentThread().getName());
            }, 5, TimeUnit.SECONDS);
        }

        executor.shutdown();
        executor.awaitTermination(15, TimeUnit.SECONDS);
    }
}

