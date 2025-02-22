package com.example.application.ports.inbound;

public interface SetCache <K, V> {
    public V setCache(K key, V value);
}
