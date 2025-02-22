package com.example.application.ports.outbound;

public interface EvictionPolicy <K> {
    public K evictionCandidate();
    public void keyAccessed(K key);
    public void keyRemoved(K key);
    public void keyAdded(K key);
    public void clear();
}
