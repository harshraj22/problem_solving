package com.example.application.ports.outbound;

import com.example.application.models.Event;

// Note: Though this interface expects only one method,
// in general, it would need to maintain state (e.g., count of hits, misses, etc.)
// Hence, it is defined as an interface rather than a functional interface.
public interface CacheHook<K, V> {
    void onEvent(Event event, K key, V value);
}
