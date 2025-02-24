package org.example.lightBulb.event;

public class LightBulbTurnOffMetric implements EventHook {
    private int turnOffCount = 0;

    @Override
    public void onEvent(Event event) {
        if (event == Event.LIGHT_BULB_TURNED_OFF) {
            turnOffCount++;
        }
    }

    public int getCount() {
        return turnOffCount;
    }
}
