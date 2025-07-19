package com.harshraj22.application.hooks;

import com.harshraj22.application.datasource.TransactionRecord;

public interface TransactionHook {
    public void onEvent(TransactionHookType type, TransactionRecord transactionRecord);
}
