package com.harshraj22.application.strategies;

import com.harshraj22.application.datasource.TransactionRecord;
import com.harshraj22.application.models.Expense;

import java.util.List;

public interface ExpenseSplitStrategy {
    public List<TransactionRecord> split(Expense expense);

}
