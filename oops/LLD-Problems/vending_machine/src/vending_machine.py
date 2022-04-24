#pylint: disable=missing-class-docstring
from typing import Optional, List
from collections import defaultdict
from src.models.product import Product


class VendingMachine:

    def __init__(self, products: Optional[List[Product]] = None) -> None:
        if products is None:
            products = []

        self.products = defaultdict(lambda: 0)
        for product in products:
            self.products[product] += 1

    @property
    def registered_products(self):
        """A generator to yield the registered products"""
        for product in self.products.keys():
            yield product

    def is_registered(self, product: Product) -> bool:
        """Check if a product is registered"""
        for _product in self.registered_products:
            if _product == product:
                return True
        return False

    def is_available(self, product: Product) -> bool:
        """Check if product is available in the inventory currently."""
        if not self.is_registered(product):
            raise KeyError(f'{product} is not registered.')
        return bool(self.products[product])

    def register(self, product_to_register: Product) -> None:
        """Register a product if it is not already present"""
        if self.is_registered(product_to_register):
            raise KeyError(f'{product_to_register} is already registered')
        self.products[product_to_register] += 1

    def buy(self, product_to_buy: Product, money: int) -> int:
        """Buy a product with the given amount of money. Returns the extra money
        if paid."""
        if not self.is_registered(product_to_buy):
            raise KeyError(f'{product_to_buy} is not registered.')
        elif not self.is_available(product_to_buy):
            raise ValueError(f'{product_to_buy} is not available currently.')
        elif product_to_buy.cost > money:
            raise ValueError('Not enough money.')

        # Note: Product class ensures that no product's cost is <= 0
        money_left = money % product_to_buy.cost
        self.products[product_to_buy] -= money // product_to_buy.cost
        return money_left

    def update_price(self, product: Product, new_price: int):
        """Update the price of each unit of the product in the inventory."""
        if not self.is_registered(product):
            raise KeyError(f'{product} is not registered.')

        for _product in self.registered_products:
            if _product == product:
                _product.cost = new_price
                break


if __name__ == '__main__':
    machine = VendingMachine([
        Product('Laptop', 3000),
        Product('Roses', 500),
        Product('Ring', 2000),
        Product('Chocolates', 5)])
    products = list(machine.registered_products)

    print(products)
    print(f'Money Left after purchasing {products[3]}: {machine.buy(products[3], 32)}')
