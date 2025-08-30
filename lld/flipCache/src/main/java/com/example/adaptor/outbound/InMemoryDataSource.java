package com.example.adaptor.outbound;

import com.example.application.ports.outbound.DataSource;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class InMemoryDataSource <K, V> implements DataSource <K, V> {
    private final Map<K, V> data;

    public InMemoryDataSource() {
        this.data = new ConcurrentHashMap<>();
    }

    @Override
    public V persist(K key, V value) {
        return data.put(key, value);
        /*
        For Testing multi-threaded access and exception handling
        System.out.println("Persisted key: " + key + ", value: " + value + " in InMemoryDataSource. Size: " + data.size());
        if (data.size() > 5) {
            throw new RuntimeException("InMemoryDataSource capacity exceeded");
        }
        */
    }

    @Override
    public V retrieve(K key) {
        return data.get(key);
    }

    @Override
    public V remove(K key) {
        return data.remove(key);
    }

    @Override
    public boolean contains(K key) {
        return data.containsKey(key);
    }
}
