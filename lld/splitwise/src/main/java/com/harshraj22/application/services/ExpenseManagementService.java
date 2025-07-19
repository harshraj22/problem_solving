package com.harshraj22.application.services;

import com.harshraj22.application.datasource.TransactionRecord;
import com.harshraj22.application.datasource.TransactionRecordDataSource;
import com.harshraj22.application.hooks.TransactionHook;
import com.harshraj22.application.hooks.TransactionHookType;
import com.harshraj22.application.models.Expense;
import com.harshraj22.application.strategies.ExpenseSplitStrategy;
import lombok.extern.slf4j.Slf4j;

import java.util.List;
import java.util.UUID;

@Slf4j
public class ExpenseManagementService {
    private final List<TransactionHook> transactionHooks = List.of(new HistoryManagementService());
    private final TransactionRecordDataSource transactionRecordDataSource = new TransactionRecordDataSource();

    public boolean addExpense(Expense expense, ExpenseSplitStrategy expenseSplitStrategy) {
        log.info("Adding expense to database");

        List<TransactionRecord> transactionRecords = expenseSplitStrategy.split(expense);

        transactionRecords.forEach(transactionRecordDataSource::addTransactionRecord);

        for (TransactionRecord transactionRecord : transactionRecords) {
            transactionHooks.forEach(
                    transactionHook -> transactionHook.onEvent(
                            TransactionHookType.EXPENSE_ADDED,
                            transactionRecord
                    )
            );
        }
        return true;
    }

    public int viewBalance(UUID fromUserId, UUID toUserId) {
        log.info("Viewing balance from user {} to user {}", fromUserId, toUserId);

        return transactionRecordDataSource.getPendingAmount(fromUserId, toUserId);
    }

    public boolean settleExpense(UUID fromUserId, UUID toUserId, int amount) {
        log.info("Setting expense from user {} to user {}", fromUserId, toUserId);

        TransactionRecord transactionRecord = new TransactionRecord(
                UUID.randomUUID(),
                fromUserId,
                toUserId,
                amount,
                null // Assuming groupId is not used in this context
        );

        transactionRecordDataSource.addTransactionRecord(transactionRecord);

        transactionHooks.forEach(
                transactionHook -> transactionHook.onEvent(
                        TransactionHookType.EXPENSE_SETTLED,
                        transactionRecord
        ));

        return true;
    }
}
