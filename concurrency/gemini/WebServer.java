package com.harshraj22;

public class WebServer {

    // 1. Create the ThreadLocal storage
    private static InheritableThreadLocal<String> currentUser = new InheritableThreadLocal<>();

    // A single thread handles this entire request
    public void handleRequest(String userId) {
        System.out.println("Started handling request for: " + userId);

        // 2. How do you SET the userId here?
        currentUser.set(userId);

        try {
            logAccess();
            fetchUserData();
        } catch (Exception e) {

        } finally {
            currentUser.remove();
        }

        System.out.println("Finished handling request for: " + userId);

        // 3. How do you CLEAN UP the userId here?
    }

    public void logAccess() {
        // 4. How do you GET the userId here?
        System.out.println("Logging access for: " + currentUser.get());
    }

    public void fetchUserData() {
        // 5. And how do you GET the userId here?
        System.out.println("Fetching data for: " + currentUser.get());
    }
}