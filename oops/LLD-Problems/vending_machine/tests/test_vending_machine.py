from src.vending_machine import VendingMachine
from src.models.product import Product
import pytest
import unittest


class TestVendingMachine(unittest.TestCase):

    def setUp(self) -> None:
        self.initial_products = [
            Product('Rose', 3),
            Product('Chocolate', 5)
        ]

        self.vending_machine = VendingMachine(products=self.initial_products)

    def test_added_products_are_yielded(self):
        for product in self.vending_machine.registered_products:
            self.assertIn(product, self.initial_products)

    def test_registered(self):
        for product in self.initial_products:
            self.assertTrue(self.vending_machine.is_registered(product))

    def test_available(self):
        for product in self.initial_products:
            self.assertTrue(self.vending_machine.is_available(product))

    def test_quantity_consistency_on_buy(self):
        self.vending_machine.buy(self.initial_products[0], self.initial_products[0].cost)
        self.assertFalse(self.vending_machine.is_available(self.initial_products[0]))

    # def test_buy_unavailable_product(self):
    #     with pytest.raises(ValueError):
    #         self.vending_machine.buy(self.initial_products[0], self.initial_products[0].cost)