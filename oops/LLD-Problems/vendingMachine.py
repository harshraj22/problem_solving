'''
Problem Statement: You need to write code to implement a Vending machine that has a bunch of products like chocolates, candy, cold-drink, and accept some coins like Nickle, Dime, Quarter, Cent, etc. Make sure you insert a coin, get a product back, and get your chance back. Also, write the Unit test to demonstrate that these common use cases work.

Problem Source: https://medium.com/javarevisited/25-software-design-interview-questions-to-crack-any-programming-and-technical-interviews-4b8237942db0

To Do:
    1. Write Unit tests
    2. Accept different denomination of currency, and change them in vending machine
'''

from enum import Enum

class Product:
    def __init__(self, name, cost=0, count=0):
        self.name = name
        self.cost = cost
        self._count = count

    def __str__(self):
        return f'{self.name} : priced at {self.cost} each, total units = {self._count}'
    
    @property
    def count(self):
        return self._count
    
    @count.setter
    def count(self, newCount):
        if newCount < 0:
            print('Count can not be negative')
        else:
            self._count = newCount

class AvailableProducts(Enum):
    CHOCOLATES = 1
    CANDY = 2
    COLDDRINK = 3

class VendingMachine:
    def __init__(self, products=None):
        if not products:
            products = {product: Product(product) for product in AvailableProducts}
        self._products = products

    def buy(self, product, money):
        if product not in AvailableProducts:
            print(f'Product {product} is not sold here.')
            return (False, money)
        elif money < self._products[product].cost:
            print(f'Not Enough Money. One item costs {self._products[product].cost}') 
            return (False, money)
        else:
            print(f'You bought {product}')
            self._products[product].count = self._products[product].count + 1 
            return (True, money - self._products[product].cost)

    def list_products(self):
        print(self._products.keys())
        


machine = VendingMachine()
did_buy, money_left = machine.buy(AvailableProducts.CANDY, 3)
machine.list_products()