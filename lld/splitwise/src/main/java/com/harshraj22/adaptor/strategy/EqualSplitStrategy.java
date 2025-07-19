package com.harshraj22.adaptor.strategy;

import com.harshraj22.application.datasource.TransactionRecord;
import com.harshraj22.application.models.Expense;
import com.harshraj22.application.strategies.ExpenseSplitStrategy;

import java.util.List;
import java.util.UUID;

public class EqualSplitStrategy implements ExpenseSplitStrategy {
    @Override
    public List<TransactionRecord> split(Expense expense) {
        double perHeadShare = (double) expense.getAmount() / expense.getParticipants().size();
        return expense.getParticipants().stream().map(
            participant -> new TransactionRecord(
                UUID.randomUUID(),
                expense.getPaidByUserId(),
                participant.getId(),
                (int) Math.round(perHeadShare),
                expense.getId()
            )
        ).toList();
    }
}
