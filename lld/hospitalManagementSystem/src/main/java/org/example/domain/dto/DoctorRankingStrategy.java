package org.example.domain.dto;

import java.util.List;

public interface DoctorRankingStrategy {
    public List<Doctor> rankDoctors(List<Doctor> doctors);
}
