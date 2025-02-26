package org.example.coffeeVendingMachine;

import org.example.coffeeVendingMachine.coffee.Coffee;
import org.example.coffeeVendingMachine.coffee.CoffeeManager;
import org.example.coffeeVendingMachine.coffee.CoffeeType;
import org.example.coffeeVendingMachine.ingredient.Ingredient;
import org.example.coffeeVendingMachine.ingredient.IngredientInventory;
import org.example.coffeeVendingMachine.payment.Payment;

import java.util.ArrayList;
import java.util.List;

public class CoffeeVendingMachine {
    public CoffeeManager coffeeManager;
    public IngredientInventory ingredientInventory;
    public List<Observer> observers = new ArrayList<>();

    public CoffeeVendingMachine(CoffeeManager coffeeManager, IngredientInventory ingredientInventory) {
        this.coffeeManager = coffeeManager;
        this.ingredientInventory = ingredientInventory;
    }

    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    public boolean buyCoffee(CoffeeType coffeeType, Payment payment) {
        // check if coffee is available
        if (!coffeeManager.isAvailable(coffeeType)) {
            return false;
        }

        Coffee coffee = coffeeManager.getCoffee(coffeeType).get();

        // check if ingredients are available
        if (!ingredientInventory.isSufficient(coffee.getIngredientInventory())) {
            return false;
        }

        // payment checks
        if (payment.getAmount() < coffee.getPrice()) {
            return false;
        }

        // update the inventory
        for (Ingredient ingredient: coffee.getIngredientInventory().getIngredients()) {
            int currentQuantity = ingredientInventory.getQuantity(ingredient.getIngredientType());
            ingredientInventory.updateQuantity(ingredient.getIngredientType(), currentQuantity - ingredient.getQuantity());
            observers.forEach(observer -> observer.onIngredientUpdate(ingredient.getIngredientType(), ingredient.getQuantity()));
        }

        return true;
    }
}

