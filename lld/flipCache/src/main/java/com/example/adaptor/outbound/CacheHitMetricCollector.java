package com.example.adaptor.outbound;

import com.example.application.models.Event;
import com.example.application.ports.outbound.CacheHook;

import java.util.HashMap;
import java.util.Map;

public class CacheHitMetricCollector <K, V> implements CacheHook <K, V> {
    private final Map<K, Integer> hitCounts = new HashMap<>();

    public int getCacheHitCount(K key) {
        return hitCounts.getOrDefault(key, 0);
    }

    @Override
    public void onEvent(Event event, K key, V value) {
        if (event == Event.HIT) {
            hitCounts.put(key, getCacheHitCount(key) + 1);
        }
    }

}
