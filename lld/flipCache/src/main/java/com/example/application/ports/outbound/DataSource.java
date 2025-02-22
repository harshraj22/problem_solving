package com.example.application.ports.outbound;

public interface DataSource <K, V> {
    public V persist(K key, V value);
    public V retrieve(K key);
    public V remove(K key);
    public boolean contains(K key);
}
