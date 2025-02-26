package org.example;

import org.example.coffeeVendingMachine.CoffeeVendingMachine;
import org.example.coffeeVendingMachine.coffee.CoffeeManager;
import org.example.coffeeVendingMachine.coffee.CoffeeType;
import org.example.coffeeVendingMachine.coffee.Expresso;
import org.example.coffeeVendingMachine.coffee.Lattee;
import org.example.coffeeVendingMachine.ingredient.IngredientInventory;
import org.example.coffeeVendingMachine.ingredient.IngredientType;
import org.example.coffeeVendingMachine.ingredient.QuantityUpdatableIngredient;
import org.example.coffeeVendingMachine.payment.Payment;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        CoffeeManager coffeeManager = new CoffeeManager(
                new ArrayList<>(List.of(
                        new Expresso(10),
                        new Lattee(15)
                ))
        );

        IngredientInventory ingredientInventory = new IngredientInventory(
                new ArrayList<>(List.of(
                        new QuantityUpdatableIngredient(IngredientType.COFFEE, 10),
                        new QuantityUpdatableIngredient(IngredientType.SUGAR, 20)
              ))
        );

        CoffeeVendingMachine coffeeVendingMachine = new CoffeeVendingMachine(coffeeManager, ingredientInventory);
        boolean coffeeBought = coffeeVendingMachine.buyCoffee(CoffeeType.ESPRESSO, new Payment(10));

        System.out.println("Tried to buy coffee, and the status was: " + coffeeBought);
    }
}