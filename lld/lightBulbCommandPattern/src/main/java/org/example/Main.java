package org.example;

import org.example.lightBulb.LightBulb;
import org.example.lightBulb.LightBulbTurnOnCommand;
import org.example.lightBulb.Remote;
import org.example.lightBulb.event.LightBulbTurnOnMetric;

public class Main {
    public static void main(String[] args) {
        Remote remote = new Remote();
        LightBulb lightBulb = new LightBulb();
        LightBulbTurnOnCommand lightBulbTurnOnCommand = new LightBulbTurnOnCommand(lightBulb);
        LightBulbTurnOnMetric lightBulbTurnOnMetric = new LightBulbTurnOnMetric();
        lightBulbTurnOnCommand.addEventHook(lightBulbTurnOnMetric);

        remote.addCommand(lightBulbTurnOnCommand);
        remote.pressButton();
        remote.pressUndo();
    }
}