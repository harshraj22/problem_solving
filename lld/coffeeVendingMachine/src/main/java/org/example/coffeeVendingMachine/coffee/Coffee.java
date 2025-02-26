package org.example.coffeeVendingMachine.coffee;

import lombok.Getter;
import org.example.coffeeVendingMachine.ingredient.IngredientInventory;

@Getter
public abstract class Coffee {
    private final CoffeeType coffeeType;
    private int price;
    private final IngredientInventory ingredientInventory;

    protected Coffee(CoffeeType coffeeType, int price, IngredientInventory ingredientInventory) {
        this.coffeeType = coffeeType;
        this.price = price;
        this.ingredientInventory = ingredientInventory;
    }
}
