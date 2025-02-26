package org.example.coffeeVendingMachine.ingredient;

public class QuantityUpdatableIngredient extends Ingredient {
    public QuantityUpdatableIngredient(IngredientType ingredientType, int quantity) {
        super(ingredientType, quantity);
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}
