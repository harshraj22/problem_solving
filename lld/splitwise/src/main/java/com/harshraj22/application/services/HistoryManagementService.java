package com.harshraj22.application.services;

import com.harshraj22.application.datasource.TransactionRecord;
import com.harshraj22.application.hooks.TransactionHook;
import com.harshraj22.application.hooks.TransactionHookType;
import lombok.extern.slf4j.Slf4j;

@Slf4j
public class HistoryManagementService implements TransactionHook {
    @Override
    public void onEvent(TransactionHookType type, TransactionRecord transactionRecord) {
        log.info("Recording History for transaction event: {} for record: {}", type, transactionRecord);

        // ToDo: Implement the logic to handle the event based on the type
    }
}
