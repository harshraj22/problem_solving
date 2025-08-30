package com.example;

import com.example.adaptor.outbound.CacheHitMetricCollector;
import com.example.adaptor.outbound.InMemoryDataSource;
import com.example.adaptor.outbound.SimpleEvictionPolicy;
import com.example.application.ports.outbound.CacheHook;
import com.example.application.ports.outbound.DataSource;
import com.example.application.ports.outbound.EvictionPolicy;
import com.example.application.service.FlipCache;

import java.util.List;

public class Main {
    public static void main(String[] args) {
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

//        System.out.println(String.format("Metric collected: Number of hits: {%s}",));
    }
}