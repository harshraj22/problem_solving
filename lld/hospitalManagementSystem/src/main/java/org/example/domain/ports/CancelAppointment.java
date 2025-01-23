package org.example.domain.ports;

import org.example.domain.dto.Doctor;
import org.example.domain.dto.Patient;

public interface CancelAppointment {
    public boolean cancelAppointment(Patient patient, Doctor doctor, Integer startTime);
}
