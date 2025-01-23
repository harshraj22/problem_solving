package org.example.domain.service;

import org.example.domain.dto.Doctor;
import org.example.domain.dto.DoctorRankingStrategy;

import java.util.List;

public class DefaultRankingStrategy implements DoctorRankingStrategy {
    @Override
    public List<Doctor> rankDoctors(List<Doctor> doctors) {
        return doctors;
    }
}
