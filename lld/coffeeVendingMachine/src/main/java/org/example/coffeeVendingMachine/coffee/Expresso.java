package org.example.coffeeVendingMachine.coffee;

import org.example.coffeeVendingMachine.ingredient.FixedQuantityIngredient;
import org.example.coffeeVendingMachine.ingredient.Ingredient;
import org.example.coffeeVendingMachine.ingredient.IngredientInventory;
import org.example.coffeeVendingMachine.ingredient.IngredientType;

import java.util.List;

public class Expresso extends Coffee {
    public Expresso(int price) {
        super(CoffeeType.ESPRESSO, price, new IngredientInventory(
                List.of(
                        (Ingredient) new FixedQuantityIngredient(IngredientType.COFFEE, 1),
                        (Ingredient) new FixedQuantityIngredient(IngredientType.SUGAR, 1)
                )
        ));
    }
}
