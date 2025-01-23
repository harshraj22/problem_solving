package org.example.domain.dto;

import java.util.ArrayList;

public class TimeSlot {
    private ArrayList<Boolean> availability = new ArrayList<>(24);
    private ArrayList<Boolean> availableSlots = new ArrayList<>(24);

    public TimeSlot(ArrayList<Boolean> availability) {
        this.availability = availability;
        for (int i = 0; i < 24; i++) {
            if (availability.get(i)) {
                availableSlots.add(Boolean.TRUE);
            } else {
                availableSlots.add(Boolean.FALSE);
            }
        }
    }

    public boolean isSlotAvailable(Integer startTime) {
        if (startTime < 0 || startTime >= 24) {
            return false;
        } else if (!availability.get(startTime)) {
            return false;
        }

        return availableSlots.get(startTime);
    }

    public boolean bookSlot(Integer startTime) {
        if (startTime < 0 || startTime >= 24) {
            return false;
        } else if (!availability.get(startTime)) {
            return false;
        } else if (!availableSlots.get(startTime)) {
            return false;
        }

        availableSlots.set(startTime, Boolean.FALSE);

        return true;
    }

    public boolean emptySlot(Integer startTime) {
        if (startTime < 0 || startTime >= 24) {
            return false;
        } else if (!availability.get(startTime)) {
            return false;
        } else if (availableSlots.get(startTime)) {
            return false;
        }

        availableSlots.set(startTime, Boolean.TRUE);

        return true;
    }
}
