package com.harshraj22.application.datasource;

import lombok.NonNull;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

@Slf4j
@RequiredArgsConstructor
public class TransactionRecordDataSource {
    @NonNull
    private final List<TransactionRecord> transactionRecords = new ArrayList<>();

    public void addTransactionRecord(@NonNull TransactionRecord transactionRecord) {
        transactionRecords.add(transactionRecord);
    }

    public int getPendingAmount(@NonNull UUID fromUserId, @NonNull UUID toUserId) {
        return transactionRecords.stream()
                .filter(record -> record.getFromUserId().equals(fromUserId) && record.getToUserId().equals(toUserId))
                .mapToInt(TransactionRecord::getAmount)
                .sum();
    }
}
