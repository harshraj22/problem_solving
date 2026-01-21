package com.example;

import com.example.adaptor.outbound.CacheHitMetricCollector;
import com.example.adaptor.outbound.InMemoryDataSource;
import com.example.adaptor.outbound.SimpleEvictionPolicy;
import com.example.application.ports.outbound.CacheHook;
import com.example.application.ports.outbound.DataSource;
import com.example.application.ports.outbound.EvictionPolicy;
import com.example.application.service.FlipCache;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Main {
    public static void main(String[] args) {
        try {
            multiThreadExecutor();
        } catch (ExecutionException | InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    public static void multiThreadExecutor() throws ExecutionException, InterruptedException {
        // Use fixed thread pool for better thread safety testing
        ExecutorService executorService = Executors.newFixedThreadPool(10);
        try {
            // add code to measure how long it takes to execute the test
            long startTime = System.currentTimeMillis();
            testCacheThreadSafety(executorService);
            long endTime = System.currentTimeMillis();
            System.out.println("======Test completed in " + (endTime - startTime) + " ms =======");
        } finally {
            executorService.shutdown();
            if (!executorService.awaitTermination(10, java.util.concurrent.TimeUnit.SECONDS)) {
                executorService.shutdownNow();
            }
        }
    }

    private static void testCacheThreadSafety(ExecutorService executorService) throws ExecutionException, InterruptedException {
        // Setup cache
        DataSource<String, String> dataSource = new InMemoryDataSource<>();
        EvictionPolicy<String> evictionPolicy = new SimpleEvictionPolicy<>();
        FlipCache<String, String> flipCache = new FlipCache<>(5, dataSource, evictionPolicy);

        CacheHook<String, String> cacheHitMetricCollector = new CacheHitMetricCollector<>();
        flipCache.registerHook(cacheHitMetricCollector);

        // Submit multiple concurrent tasks
        List<Future<?>> futures = new ArrayList<>();

        // Concurrent writes
        int concurrentHitCount = 20_000;
        for (int i = 0; i < concurrentHitCount; i++) {
            final int threadId = i;
            futures.add(executorService.submit(() -> {
                String key = "key" + (threadId % 10);
                String value = "value" + threadId;
                flipCache.setCache(key, value);
                System.out.println("Thread " + threadId + " set: " + key + " = " + value);
            }));
        }

        // Concurrent reads
        for (int i = 0; i < concurrentHitCount; i++) {
            final int threadId = i;
            futures.add(executorService.submit(() -> {
                String key = "key" + (threadId % 10);
                String value = flipCache.getCache(key);
                System.out.println("Thread " + threadId + " got: " + key + " = " + value);
            }));
        }

        // Wait for all tasks to complete
        for (Future<?> future : futures) {
            future.get();
        }

        System.out.println("All concurrent operations completed");
        System.out.println("Final cache state and metrics:");

        // Check final state
        for (int i = 0; i < 10; i++) {
            String key = "key" + i;
            String value = flipCache.getCache(key);
            int hitCount = ((CacheHitMetricCollector) cacheHitMetricCollector).getCacheHitCount(key);
            System.out.println(key + " = " + value + ", hits: " + hitCount);
        }
    }

    public static void singleThreadExecutor() {
        List<String> keys = List.of("A", "B", "C");
        int maxSizeOfCache = 2;

        DataSource<String, String> dataSource = new InMemoryDataSource<>();
        EvictionPolicy<String> evictionPolicy = new SimpleEvictionPolicy<>();
        FlipCache<String, String> flipCache = new FlipCache<>(maxSizeOfCache, dataSource, evictionPolicy);

        CacheHook<String, String> cacheHitMetricCollector = new CacheHitMetricCollector<>();
        flipCache.registerHook(cacheHitMetricCollector);

        flipCache.setCache(keys.get(0), "ValueA");
        flipCache.setCache(keys.get(1), "ValueB");
        flipCache.setCache(keys.get(2), "ValueC");

        keys.forEach(
                key -> System.out.println(String.format("Got Value: {%s} from cache for key: {%s}", flipCache.getCache(key), key))
        );

        System.out.println(String.format("Metric collected: Number of hits: {%s}", ((CacheHitMetricCollector)cacheHitMetricCollector).getCacheHitCount("A")));
    }
}