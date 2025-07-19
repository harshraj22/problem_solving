package com.harshraj22.application.models;


import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

import java.util.UUID;

@Data
@RequiredArgsConstructor
public class User {
    @NonNull
    private final UUID id;
    @NonNull
    private final Profile profile;
}
