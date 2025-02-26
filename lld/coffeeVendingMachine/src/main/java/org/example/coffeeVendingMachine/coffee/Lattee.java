package org.example.coffeeVendingMachine.coffee;

import org.example.coffeeVendingMachine.ingredient.FixedQuantityIngredient;
import org.example.coffeeVendingMachine.ingredient.Ingredient;
import org.example.coffeeVendingMachine.ingredient.IngredientInventory;
import org.example.coffeeVendingMachine.ingredient.IngredientType;

import java.util.List;

public class Lattee extends Coffee {
    public Lattee(int price) {
        super(CoffeeType.ESPRESSO, price, new IngredientInventory(
                List.of(
                        (Ingredient) new FixedQuantityIngredient(IngredientType.COFFEE, 1),
                        (Ingredient) new FixedQuantityIngredient(IngredientType.SUGAR, 2)
                )
        ));
    }
}
