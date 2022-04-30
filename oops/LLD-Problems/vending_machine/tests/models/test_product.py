from src.models.product import Product
import unittest
import pytest


class TestProduct(unittest.TestCase):

    def test_fails_non_positive_initialization(self):
        with pytest.raises(ValueError):
            _ = Product('Rose', 0)

    def test_fails_non_positive_assignment(self):
        with pytest.raises(ValueError):
            rose = Product('Rose', 3)
            rose.cost = -2

    def test_product_equality(self):
        """Product equality is being directly used in Vending Machine class 
        and thus is must to pass."""
        rose = Product('Rose', 3)
        rose2 = Product('Rose', 3)
        keyboard = Product('Keyboard', 2300)

        self.assertEqual(rose, rose2)
        self.assertNotEqual(rose, keyboard)

    def test_hash_equality(self):
        rose = Product('Rose', 3)
        rose2 = Product('Rose', 3)
        keyboard = Product('Keyboard', 2300)

        self.assertEqual(hash(rose), hash(rose2))
        self.assertNotEqual(hash(rose), hash(keyboard))