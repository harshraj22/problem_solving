#pylint: disable=missing-class-docstring
"""
Module for Product class.


"""

class Product:

    #ToDo: No Product can be free. Use Metaclass to confirm this.
    def __init__(self, name: str, cost: int) -> None:
        self.name = name
        self._cost = cost

    @property
    def cost(self):
        return self._cost

    @cost.setter
    def cost(self, new_cost: int):
        self._cost = new_cost

    def __eq__(self, other) -> bool:
        return self.name == other.name

    def __str__(self) -> str:
        return f'Product({self.name}, {self.cost})'
    
    def __repr__(self) -> str:
        return str(self)

    def __hash__(self) -> int:
        # To enable a product be a key of a dict
        return hash(self.name)
