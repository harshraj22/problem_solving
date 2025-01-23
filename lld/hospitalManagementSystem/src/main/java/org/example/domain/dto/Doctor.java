package org.example.domain.dto;

import lombok.Getter;

import java.util.ArrayList;
import java.util.HashMap;

@Getter
public class Doctor {
    private DoctorSpeciality doctorSpeciality;
    private TimeSlot timeSlot;
    private String id;

    public Doctor(String id, DoctorSpeciality doctorSpeciality) {
        this.id = id;
        this.doctorSpeciality = doctorSpeciality;
    }

    public void declareAvailability(TimeSlot timeSlot) {
        this.timeSlot = timeSlot;
    }

    public boolean isSlotAvailable(Integer startTime) {
        return timeSlot.isSlotAvailable(startTime);
    }

    public boolean bookSlot(Integer startTime) {
        return timeSlot.bookSlot(startTime);
    }

    public boolean cancelSlot(Integer startTime) {
        return timeSlot.emptySlot(startTime);
    }
}
