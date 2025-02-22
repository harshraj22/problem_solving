package com.example.adaptor.outbound;

import com.example.application.ports.outbound.EvictionPolicy;

import java.util.ArrayList;
import java.util.List;

public class SimpleEvictionPolicy <K> implements EvictionPolicy <K> {
    private final List<K> keys;

    public SimpleEvictionPolicy() {
        this.keys = new ArrayList<>();
    }

    @Override
    public K evictionCandidate() {
        return keys.getLast();
    }

    @Override
    public void keyAccessed(K key) {

    }

    @Override
    public void keyRemoved(K key) {
        keys.remove(key);
    }

    @Override
    public void keyAdded(K key) {
        keys.add(key);
    }

    @Override
    public void clear() {
        keys.clear();
    }
}
