package org.example.lightBulb;

import org.example.lightBulb.event.Event;
import org.example.lightBulb.event.EventHook;

import java.util.ArrayList;
import java.util.List;

public class LightBulb {
    private boolean isOn = false;
    private List<EventHook> eventHooks = new ArrayList<>();

    public void addEventHook(EventHook eventHook) {
        eventHooks.add(eventHook);
    }

    private void triggerHooks(Event event) {
        for (EventHook hook : eventHooks) {
            hook.onEvent(event);
        }
    }

    public void turnOn() {
        isOn = true;
        triggerHooks(Event.LIGHT_BULB_TURNED_ON);
        System.out.println("Light turned on.");
    }

    public void turnOff() {
        isOn = false;
        triggerHooks(Event.LIGHT_BULB_TURNED_OFF);
        System.out.println("Light turned off.");
    }

    public boolean isOn() {
        return isOn;
    }
}
