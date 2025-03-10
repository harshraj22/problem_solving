package com.example.application.service;

import com.example.application.models.Event;
import com.example.application.ports.inbound.GetCache;
import com.example.application.ports.inbound.SetCache;
import com.example.application.ports.outbound.DataSource;
import com.example.application.ports.outbound.EvictionPolicy;
import com.example.application.ports.outbound.CacheHook;

import java.util.ArrayList;
import java.util.List;

public class FlipCache<K, V> implements GetCache<K, V>, SetCache<K, V> {
    private final int maxSize;
    private int currentSize;
    private final DataSource<K, V> dataSource;
    private final EvictionPolicy<K> evictionPolicy;
    private final List<CacheHook<K, V>> hooks;

    public FlipCache(int maxSize, DataSource<K, V> dataSource, EvictionPolicy<K> evictionPolicy) {
        this.maxSize = maxSize;
        this.dataSource = dataSource;
        this.evictionPolicy = evictionPolicy;
        this.hooks = new ArrayList<>();
        this.currentSize = 0;
    }

    private void triggerHooks(Event event, K key, V value) {
        hooks.forEach(
                metric -> metric.onEvent(event, key, value)
        );
    }

    public CacheHook<K, V> registerHook(CacheHook<K, V> cacheHook) {
        this.hooks.add(cacheHook);
        return cacheHook;
    }

    @Override
    public V getCache(K key) {
        V value = this.dataSource.retrieve(key);
        if (value == null) {
            triggerHooks(Event.MISS, key, value);
        } else {
            triggerHooks(Event.HIT, key, value);
        }

        return value;
    }

    @Override
    public V setCache(K key, V value) {
        // if key already exists
        if (dataSource.contains(key)) {
            evictionPolicy.keyAccessed(key);
            return dataSource.retrieve(key);
        }

        // If the cache is full, evict an item
        if (currentSize == maxSize) {
            K keyToEvict = evictionPolicy.evictionCandidate();
            triggerHooks(Event.EVICT, keyToEvict, dataSource.retrieve(keyToEvict));
            dataSource.remove(keyToEvict);
            evictionPolicy.keyRemoved(keyToEvict);
            currentSize -= 1;
        }

        // persist the data
        dataSource.persist(key, value);
        evictionPolicy.keyAdded(key);
        currentSize += 1;

        // Add appropriate metrics
        triggerHooks(Event.CREATE, key, value);

        return value;
    }
}
