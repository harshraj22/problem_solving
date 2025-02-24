package org.example.lightBulb;

import org.example.lightBulb.event.EventHook;

public class LightBulbTurnOffCommand implements Command{
    LightBulb lightBulb;

    public LightBulbTurnOffCommand(LightBulb lightBulb) {
        this.lightBulb = lightBulb;
    }

    public void addEventHook(EventHook eventHook) {
        lightBulb.addEventHook(eventHook);
    }

    @Override
    public void execute() {
        lightBulb.turnOff();
    }

    @Override
    public void undo() {
        lightBulb.turnOn();
    }

    @Override
    public void redo() {
        execute();
    }
}
