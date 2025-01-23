package org.example.domain.dto;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class Appointment {
    private Doctor doctor;
    private Patient patient;
    private Integer startTime;
}

