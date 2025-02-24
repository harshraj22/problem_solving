package org.example.lightBulb;

import org.example.lightBulb.event.EventHook;

public class LightBulbTurnOnCommand implements Command{
    LightBulb lightBulb;

    public LightBulbTurnOnCommand(LightBulb lightBulb) {
        this.lightBulb = lightBulb;
    }

    public void addEventHook(EventHook eventHook) {
        lightBulb.addEventHook(eventHook);
    }

    @Override
    public void execute() {
        lightBulb.turnOn();
    }

    @Override
    public void undo() {
        lightBulb.turnOff();
    }

    @Override
    public void redo() {
        execute();
    }
}
