package org.example.coffeeVendingMachine.ingredient;

import lombok.AllArgsConstructor;
import lombok.Getter;

import java.util.List;
import java.util.Optional;

@Getter
@AllArgsConstructor
public class IngredientInventory {
    private final List<Ingredient> ingredients;

    private Optional<Ingredient> getIngredient(IngredientType ingredientType) {
        for (Ingredient ingredient : ingredients) {
            if (ingredient.getIngredientType() == ingredientType) {
                return Optional.of(ingredient);
            }
        }
        return Optional.empty();
    }

    public boolean isSufficient(IngredientInventory requiredIngredients) {
        for (Ingredient requiredIngredient : requiredIngredients.getIngredients()) {
            Optional<Ingredient> inventoryIngredient = getIngredient(requiredIngredient.getIngredientType());
            if (inventoryIngredient.isEmpty() || inventoryIngredient.get().getQuantity() < requiredIngredient.getQuantity()) {
                return false;
            }
        }
        return true;
    }

    private void updateIngredients(Ingredient ingredient) {
        Optional<Ingredient> inventoryIngredient = getIngredient(ingredient.getIngredientType());
        inventoryIngredient.ifPresent(ingredients::remove);

        ingredients.add(ingredient);
    }

    public int getQuantity(IngredientType ingredientType) {
        Optional<Ingredient> ingredient = getIngredient(ingredientType);
        return ingredient.map(Ingredient::getQuantity).orElse(0);
    }

    public void updateQuantity(IngredientType ingredientType, int quantity) {
        updateIngredients(new QuantityUpdatableIngredient(ingredientType, quantity));
    }
}
