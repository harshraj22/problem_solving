package com.example.adaptor.outbound;

import com.example.application.models.Event;
import com.example.application.ports.outbound.CacheHook;

public class CacheHitMetricCollector <K, V> implements CacheHook <K, V> {
    private int cacheHitCount = 0;
    private final K key;

    public CacheHitMetricCollector(K key) {
        this.key = key;
    }

    public int getCacheHitCount() {
        return cacheHitCount;
    }

    @Override
    public void onEvent(Event event, K key, V value) {
        if (event == Event.HIT && key.equals(this.key)) {
            cacheHitCount += 1;
        }
    }

}
