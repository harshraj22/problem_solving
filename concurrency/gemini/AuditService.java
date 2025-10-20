package com.harshraj22;

//import java.util.concurrent.ScopedValue;

import java.util.concurrent.Executors;
import java.util.concurrent.ForkJoinPool;

public class AuditService {

    // 1. How do we define our ScopedValue to hold the requestId?
    private static final ScopedValue<String> REQUEST_ID = ScopedValue.newInstance();

    // This is the main entry point that receives the request
    public void processRequest(String requestId) {
        System.out.println("START: Processing " + requestId);

        // 2. How do we bind the requestId to the scope
        //    and run the handleRequest() method inside it?
        ScopedValue.where(REQUEST_ID, requestId).run(() -> handleRequest());

        System.out.println("END: Processing " + requestId);
    }

    // This method runs "inside" the scope
    private void handleRequest() {
        // 3. How do we get the requestId here?
        String id = REQUEST_ID.get();
        System.out.println("-> Main handler logging for: " + id);

        // We'll add this part in the next step
         Thread backgroundThread = new Thread(() -> saveAuditLog());
         backgroundThread.start();
         backgroundThread.setDaemon(true);
    }

    // This method will also run "inside" the scope
    private void saveAuditLog() {
        String id = REQUEST_ID.get();
        System.out.println("--> Audit log saving for: " + id);
    }
}