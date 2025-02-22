package com.example.application.ports.inbound;

public interface GetCache <K, V> {
    public V getCache(K key);
}
