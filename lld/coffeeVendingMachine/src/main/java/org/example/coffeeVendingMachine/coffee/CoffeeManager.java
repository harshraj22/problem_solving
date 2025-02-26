package org.example.coffeeVendingMachine.coffee;

import lombok.AllArgsConstructor;

import java.util.List;
import java.util.Optional;

@AllArgsConstructor
public class CoffeeManager {
    List<Coffee> coffeeList;

    public boolean isAvailable(CoffeeType coffeeType) {
        return coffeeList.stream().anyMatch(coffee -> coffee.getCoffeeType().equals(coffeeType));
    }

    public Optional<Coffee> getCoffee(CoffeeType coffeeType) {
        return coffeeList.stream().filter(coffee -> coffee.getCoffeeType().equals(coffeeType)).findFirst();
    }
}
