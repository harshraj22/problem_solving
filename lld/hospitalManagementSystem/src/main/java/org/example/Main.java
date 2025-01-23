package org.example;

import org.example.domain.dto.Doctor;
import org.example.domain.dto.DoctorSpeciality;
import org.example.domain.dto.Patient;
import org.example.domain.dto.TimeSlot;
import org.example.domain.service.HospitalManagementSystem;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        HospitalManagementSystem hospitalManagementSystem = new HospitalManagementSystem();
        Doctor johnDoe = new Doctor("John Doe", DoctorSpeciality.CARDIOLOGIST);
        Doctor simaJone = new Doctor("Sima Jone", DoctorSpeciality.CARDIOLOGIST);

        hospitalManagementSystem.registerDoctor(johnDoe);
        hospitalManagementSystem.registerDoctor(simaJone);

        Patient patient = new Patient("Kallu Kalia");
        Patient patient1 = new Patient("Gogo");

        // John Doe is available from 9 to 10 AM
        ArrayList<Boolean> johnDoeAvailability = new ArrayList<>(24);
        for (int i = 0; i < 24; i++) {
            johnDoeAvailability.add(Boolean.FALSE);
        }
        johnDoeAvailability.set(0, Boolean.TRUE);
        johnDoeAvailability.set(1, Boolean.TRUE);
        johnDoe.declareAvailability(new TimeSlot(johnDoeAvailability));

        // Sima Jone is available from 9:30 to 11 AM
        ArrayList<Boolean> simaJoneAvailability = new ArrayList<>(24);
        for (int i = 0; i < 24; i++) {
            simaJoneAvailability.add(Boolean.FALSE);
        }
        simaJoneAvailability.set(1, Boolean.FALSE);
        simaJoneAvailability.set(2, Boolean.FALSE);
        simaJoneAvailability.set(3, Boolean.FALSE);
        simaJone.declareAvailability(new TimeSlot(simaJoneAvailability));

        boolean isAppointmentBooked1 = hospitalManagementSystem.bookAppointment(patient, johnDoe, 0);
        System.out.println(String.format("Patient %s tried booking appointment with doctor %s with response: %s", patient.getId(), johnDoe.getId(), isAppointmentBooked1));

        boolean isAppointmentBooked2 = hospitalManagementSystem.bookAppointment(patient1, johnDoe, 0);
        System.out.println(String.format("Patient %s tried booking appointment with doctor %s with response: %s", patient1.getId(), johnDoe.getId(), isAppointmentBooked2));

        boolean isAppointmentCancelled = hospitalManagementSystem.cancelAppointment(patient, johnDoe, 0);
        System.out.println(String.format("Patient %s tried cancelling appointment with doctor %s with response: %s", patient.getId(), johnDoe.getId(), isAppointmentCancelled));

        boolean isAppointmentBooked3 = hospitalManagementSystem.bookAppointment(patient1, johnDoe, 0);
        System.out.println(String.format("Patient %s tried booking appointment with doctor %s with response: %s", patient1.getId(), johnDoe.getId(), isAppointmentBooked3));

    }
}