package com.harshraj22.application.models;

import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

@Data
@RequiredArgsConstructor
public class Profile {
    @NonNull
    private final String name;

}
