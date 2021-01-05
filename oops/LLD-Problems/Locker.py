''' Problem Statement: https://leetcode.com/discuss/interview-question/object-oriented-design/260467/Amazon-or-Design-a-locker
'''

import unittest
from typing import Type


class ThreeDimentional:
	""" Base class that is inherited by any 3 Dimentional object."""
	def __init__(self, height: int, width: int):
		self._height = height
		self._width = width

	@property
	def height(self) -> int:
		return self._height

	@property
	def width(self) -> int:
		return self._width

	def __lt__(self, other) -> bool:
		return self.height < other.height and self.width < other.width

	def __le__(self, other) -> bool:
		return self.height <= other.height and self.width <= other.width

	def __eq__(self, other) -> bool:
		return self.height == other.height and self.width == other.width

	def __str__(self) -> str:
		return f'A 3D object with height: {self.height} and width: {self.width}'

	def __repr__(self) -> str:
		return f'ThreeDimentional({self.height}, {self.width})'


class Package(ThreeDimentional):
	""" Package class to represent packages """

	def __init__(self, *args):
		super(Package, self).__init__(*args)

	def __str__(self) -> str:
		return f'A Package with height: {self.height} and width: {self.width}'

	def __repr__(self) -> str:
		return f'Package({self.height}, {self.width})'


class Locker(ThreeDimentional):
	""" Locker Class to store the packages """

	def __init__(self, *args):
		super(Locker, self).__init__(*args)
		self._empty = True
		self._package = None

	def is_empty(self) -> bool:
		return self._empty

	def put_package(self, other: Type[Package]) -> None:
		"""Adds package to the current locker

		Args:
			other (Package): object of Package class to be added to the Locker
		"""
		self._package = other
		self._empty = False

	def get_package(self) -> Type[Package]:
		"""Returns package stored in the current Locker

		Returns:
			Package: Returns the package stored (None by default)
		"""
		return self._package

	def evict_package(self) -> None:
		"""Removes package stored in Locker (if any)
		"""
		self._package = None

	def __str__(self) -> str:
		return f'A Locker with height: {self.height} and width: {self.width}'

	def __repr__(self) -> str:
		return f'Locker({self.height}, {self.width})'


class TestLocker(unittest.TestCase):
	def setUp(self):
		self.obj = Locker(2, 3)

	def test_empty_initially(self):
		self.assertTrue(self.obj.is_empty())

	def test_same_package_returned(self):
		package = Package(1, 1)
		self.obj.put_package(package)
		self.assertEqual(self.obj.get_package(), package)

	def test_not_empty(self):
		self.obj.put_package(Package(1, 1))
		self.assertFalse(self.obj.is_empty())


class TestThreeDimentional(unittest.TestCase):
	def setUp(self):
		self._height = 3
		self._width = 2
		self.obj = ThreeDimentional(self._height, self._width)

	def test_height(self):
		self.assertEqual(self._height, self.obj.height)

	def test_width(self):
		self.assertEqual(self._width, self.obj.width)

	def test_less_than_comparator(self):
		self.assertLess(self.obj, ThreeDimentional(50, 50))

	def test_less_that_or_equal_comparator(self):
		self.assertLessEqual(self.obj, self.obj)

	def test_equal_comparator(self):
		self.assertEqual(self.obj, self.obj)
