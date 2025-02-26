package org.example.coffeeVendingMachine;

import org.example.coffeeVendingMachine.ingredient.Ingredient;
import org.example.coffeeVendingMachine.ingredient.IngredientType;

public interface Observer {
    public void onIngredientUpdate(IngredientType ingredientType, int quantity);
}
