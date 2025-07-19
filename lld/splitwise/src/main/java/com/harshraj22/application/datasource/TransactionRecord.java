package com.harshraj22.application.datasource;

import lombok.Data;
import lombok.NonNull;
import lombok.RequiredArgsConstructor;

import java.util.UUID;

@Data
@RequiredArgsConstructor
public class TransactionRecord {
    @NonNull
    private final UUID transactionId;
    @NonNull
    private final UUID fromUserId;
    @NonNull
    private final UUID toUserId;
    private final int amount;
    private final UUID groupId;
}
