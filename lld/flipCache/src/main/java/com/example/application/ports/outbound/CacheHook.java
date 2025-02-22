package com.example.application.ports.outbound;

import com.example.application.models.Event;

public interface CacheHook<K, V> {
    void onEvent(Event event, K key, V value);
}
