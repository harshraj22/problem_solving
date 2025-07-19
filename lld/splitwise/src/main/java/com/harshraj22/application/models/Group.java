package com.harshraj22.application.models;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NonNull;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Data
@AllArgsConstructor
public class Group {
    @NonNull
    private final UUID id;
    @NonNull
    private final String name;
    @NonNull
    private List<User> members = new ArrayList<>();
}
