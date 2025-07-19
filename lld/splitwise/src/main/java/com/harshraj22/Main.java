package com.harshraj22;

import com.harshraj22.adaptor.strategy.EqualSplitStrategy;
import com.harshraj22.application.models.Expense;
import com.harshraj22.application.models.Profile;
import com.harshraj22.application.models.User;
import com.harshraj22.application.services.ExpenseManagementService;

import java.util.List;
import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        Profile profile1 = new Profile("John");
        User user1 = new User(UUID.randomUUID(), profile1);

        Profile profile2 = new Profile("Kalia");
        User user2 = new User(UUID.randomUUID(), profile2);

        ExpenseManagementService expenseManagementService = new ExpenseManagementService();
        expenseManagementService.addExpense(
                new Expense(UUID.randomUUID(), 100, "Lunch", user1.getId(), List.of(user1, user2)),
                new EqualSplitStrategy()
        );

        System.out.println(String.format("Expense from user: %s to user: %s is: %s",
                user1.getId(),
                user2.getId(),
                expenseManagementService.viewBalance(user1.getId(), user2.getId())
            )
        );

    }
}