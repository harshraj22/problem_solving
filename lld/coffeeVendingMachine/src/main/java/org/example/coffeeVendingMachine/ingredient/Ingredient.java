package org.example.coffeeVendingMachine.ingredient;

import lombok.Getter;

@Getter
public abstract class Ingredient {
    private final IngredientType ingredientType;
    public int quantity;

    public Ingredient(IngredientType ingredientType, int quantity) {
        this.ingredientType = ingredientType;
        this.quantity = quantity;
    }
}
