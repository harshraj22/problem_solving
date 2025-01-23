package org.example.domain.ports;

import org.example.domain.dto.Doctor;
import org.example.domain.dto.Patient;

public interface BookAppointment {
    public boolean bookAppointment(Patient patient, Doctor doctor, Integer startTime);
}
