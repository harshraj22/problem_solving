package com.example.adaptor.outbound;

import com.example.application.ports.outbound.DataSource;

import java.util.HashMap;
import java.util.Map;

public class InMemoryDataSource <K, V> implements DataSource <K, V> {
    private final Map<K, V> data;

    public InMemoryDataSource() {
        this.data = new HashMap<>();
    }

    @Override
    public V persist(K key, V value) {
        data.put(key, value);
        System.out.println("Persisted key: " + key + ", value: " + value + " in InMemoryDataSource. Size: " + data.size());
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
