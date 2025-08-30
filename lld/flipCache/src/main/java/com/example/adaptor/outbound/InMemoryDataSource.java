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
    public synchronized V persist(K key, V value) {
        data.put(key, value);
        /*
        For Testing multi-threaded access and exception handling
        System.out.println("Persisted key: " + key + ", value: " + value + " in InMemoryDataSource. Size: " + data.size());
        if (data.size() > 5) {
            throw new RuntimeException("InMemoryDataSource capacity exceeded");
        }
        */

        return value;
    }

    @Override
    public V retrieve(K key) {
        if (!this.contains(key)) {
            return null;
        }
        return data.get(key);
    }

    @Override
    public V remove(K key) {
        if (!this.contains(key)) {
            return null;
        }

        V value = this.retrieve(key);
        data.remove(key);
        return value;
    }

    @Override
    public boolean contains(K key) {
        return data.containsKey(key);
    }
}
