package com.harshraj22.application.models;

import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Data
@RequiredArgsConstructor
public class Expense {
    @NonNull
    private final UUID id;
    private final int amount;
    private final String description;
    @NonNull
    private final UUID paidByUserId;
    @NonNull // Participants size should be at least 1
    private final List<User> participants;
}
