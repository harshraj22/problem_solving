package org.example.domain.service;

import org.example.domain.dto.*;
import org.example.domain.ports.BookAppointment;
import org.example.domain.ports.CancelAppointment;
import org.example.domain.ports.RegisterDoctor;
import org.example.domain.ports.SearchSlotsBasedOnSpeciality;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class HospitalManagementSystem implements RegisterDoctor, SearchSlotsBasedOnSpeciality, BookAppointment, CancelAppointment {
    private ArrayList<Doctor> doctors = new ArrayList<>();
    private ArrayList<Appointment> appointments = new ArrayList<>();
    private HashMap<Doctor, HashMap<Integer, ArrayList<Patient>>> waitlist = new HashMap<>();


    @Override
    public boolean registerDoctor(Doctor doctor) {
        return doctors.add(doctor);
    }

    @Override
    public ArrayList<Doctor> searchSlotsBasedOnSpeciality(DoctorSpeciality speciality, DoctorRankingStrategy strategy) {
        List<Doctor> filteredDoctors = doctors.stream().filter(doctor -> speciality.equals(doctor.getDoctorSpeciality())).toList();
        return (ArrayList<Doctor>) strategy.rankDoctors(filteredDoctors);
    }

    @Override
    public boolean bookAppointment(Patient patient, Doctor doctor, Integer startTime) {
        if (!validateBookingAllowed(patient, doctor, startTime)) {
            return false;
        }

        appointments.add(new Appointment(doctor, patient, startTime));
        doctor.bookSlot(startTime);
        return true;
    }

    @Override
    public boolean cancelAppointment(Patient patient, Doctor doctor, Integer startTime) {
        if (!validateCancellingAllowed(patient, doctor, startTime)) {
            return false;
        }

        // find the appointment and remove it
        appointments.removeIf(appointment -> appointment.getDoctor().equals(doctor) && appointment.getPatient().equals(patient) && appointment.getStartTime().equals(startTime));
        doctor.cancelSlot(startTime);

        updateWaitlist(doctor, startTime);
        return true;
    }

    private void updateWaitlist(Doctor doctor, Integer startTime) {
        ArrayList<Patient> waitingPatients = waitlist.getOrDefault(doctor, new HashMap<>()).getOrDefault(startTime, new ArrayList<>());
        if (waitingPatients.isEmpty()) {
            return;
        }

        for (Patient patient: waitingPatients) {
            if (bookAppointment(patient, doctor, startTime)) {
                waitingPatients.remove(patient);
                break;
            }
        }
    }

    private boolean validateBookingAllowed(Patient patient, Doctor doctor, Integer startTime) {
        if (!doctor.isSlotAvailable(startTime)) {
            return false;
        }

        return appointments.stream().noneMatch(appointment -> appointment.getDoctor().equals(doctor) && appointment.getStartTime().equals(startTime));
    }

    private boolean validateCancellingAllowed(Patient patient, Doctor doctor, Integer startTime) {
        return appointments.stream().anyMatch(appointment -> appointment.getDoctor().equals(doctor) && appointment.getPatient().equals(patient) && appointment.getStartTime().equals(startTime));
    }
}
