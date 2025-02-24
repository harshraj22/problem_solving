package org.example.lightBulb.event;

public class LightBulbTurnOnMetric implements EventHook {
    private int turnOnCount = 0;
    
    @Override
    public void onEvent(Event event) {
        if (event == Event.LIGHT_BULB_TURNED_ON) {
            turnOnCount += 1;
            System.out.println("Light turned on count: " + turnOnCount);
        }
    }

    public int getCount() {
        return turnOnCount;
    }
}
