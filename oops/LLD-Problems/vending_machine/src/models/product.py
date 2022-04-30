#pylint: disable=missing-class-docstring
"""
Module for Product class.


"""

class Product:

    def __init__(self, name: str, cost: int) -> None:
        self.name = name
        self.cost = cost

    @property
    def cost(self):
        """Cost of one item of the product"""
        return self._cost

    @cost.setter
    def cost(self, new_cost: int):
        if new_cost <= 0:
            raise ValueError('Cost of a product can not be non-positive.')
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
