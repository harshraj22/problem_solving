from simulator import simulate
import unittest

# To run tests, cd into the directory this file is located, then run the following:
# python3 -m unittest simulator_test.py

class SimulationTest(unittest.TestCase):
    ''' unit tests for the simulator'''
    def test_all_drivers_know(self):
        routes = [
            [3, 1, 2, 3],
            [3, 2, 3, 1],
            [4, 2, 3, 4, 5]
        ]

        self.assertEqual(True, simulate(routes)[0])

    def test_all_drivers_do_not_know(self):
        routes = [
            [2, 1, 2],
            [5, 2, 8]
        ]

        self.assertFalse(simulate(routes)[0])


