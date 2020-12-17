"""
Problem Statement: You need to write code to implement a Vending machine that
    has a bunch of products like chocolates, candy, cold-drink, and accept some
    coins like Nickle, Dime, Quarter, Cent, etc. Make sure you insert a coin,
    get a product back, and get your chance back. Also, write the Unit test to
    demonstrate that these common use cases work.

Problem Source: https://medium.com/javarevisited/25-software-design-interview-questions-to-crack-any-programming-and-technical-interviews-4b8237942db0

To Do:
    1. Write Unit tests
    2. Accept different denomination of currency, and change them in vending
        machine

Solution by: github.com/harshraj22
"""

from enum import Enum
from typing import Optional, Tuple, Type


class Product:
    """Class representing products for sale """

    def __init__(
        self, name, cost: Optional[int] = 0, count: Optional[int] = 0
    ) -> None:
        self.name = name
        self.cost = cost
        self._count = count

    def __str__(self):
        return f"{self.name} : priced at {self.cost} each, \
            total units = {self._count}"

    @property
    def count(self):
        """method to return the count of item of given product in the vending
            machine.

        Returns:
            int: returns the count of the product.
        """
        return self._count

    @count.setter
    def count(self, new_count):
        """method to update the value of count of items of the given product
            in the vending machine. Setter allows it to be used as a property
            instead of method.

        Example:
            obj.count = 5

        Args:
            new_count (int): The count of product.
        """
        if new_count < 0:
            print("Count can not be negative")
        else:
            self._count = new_count


class AvailableProducts(Enum):
    """Enum for representing the available objects in vending machine """

    CHOCOLATES = 1
    CANDY = 2
    COLDDRINK = 3


class VendingMachine:
    """Vending Machine class depicting the usage of a typical vending machine"""

    def __init__(self, products=None):
        """Initializer for the class

        Args:
            products (dict(AvailableProducts, Products), optional): describes
                 the products available in vending machine for sale. Defaults
                 to None.
        """
        if not products:
            products = {
                product: Product(product) for product in AvailableProducts
            }
        self._products = products

    def buy(
        self, product: Type[AvailableProducts], money: int
    ) -> Tuple[bool, int]:
        """Method for buying a product from the vending machine

        Args:
            product (AvailableProducts): Describes the type of product one
                wants to buy (one of the types represented by the enum
                AvailableProducts)
            money (int): The money customer gave to the vending machine

        Returns:
            Tuple(Bool, int): A tuple whose first parameter represents if the
                purchase was successful, and the second the money returned by
                vending machine (if any) after the purchase
        """
        if product not in AvailableProducts:
            print(f"Product {product} is not sold here.")
            return (False, money)
        elif money < self._products[product].cost:
            print(
                f"Not Enough Money. One item costs \
                    {self._products[product].cost}"
            )
            return (False, money)
        else:
            print(f"You bought {product}")
            self._products[product].count = self._products[product].count + 1
            return (True, money - self._products[product].cost)

    def list_products(self):
        """Method for printing a list of available products for the vending
        machine
        """
        print(self._products.keys())


if __name__ == "__main__":
    machine = VendingMachine()
    did_buy, money_left = machine.buy(AvailableProducts.CANDY, 3)
    machine.list_products()
