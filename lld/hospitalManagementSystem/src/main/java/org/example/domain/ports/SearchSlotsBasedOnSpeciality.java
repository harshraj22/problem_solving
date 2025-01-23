package org.example.domain.ports;

import org.example.domain.dto.Doctor;
import org.example.domain.dto.DoctorRankingStrategy;
import org.example.domain.dto.DoctorSpeciality;

import java.util.ArrayList;

public interface SearchSlotsBasedOnSpeciality {
    public ArrayList<Doctor> searchSlotsBasedOnSpeciality(DoctorSpeciality speciality, DoctorRankingStrategy strategy);
}
