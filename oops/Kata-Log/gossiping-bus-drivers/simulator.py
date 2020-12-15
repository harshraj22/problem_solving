# simulates the whole experiment
from driver import Driver
from collections import defaultdict

MAX_ALLOWED_TIME = 480

class Clock:
    def __init__(self, initial_time):
        self._time = initial_time
    
    def tick(self):
        self._time += 1
    
    @property
    def time(self):
        return self._time


def simulate(routes):
    drivers = [Driver(index, route) for index, route in enumerate(routes)]
    clock = Clock(0)
    all_know_others = False

    while clock.time < MAX_ALLOWED_TIME and not all_know_others:
        clock.tick()
        meeting_points = defaultdict(set)

        # drivers at same stop, meet each other and share gossips
        for driver in drivers:
            driver.move_next()
            meeting_points[driver.current_stop] = meeting_points[driver.current_stop] | driver.knows

        # drivers collect other drivers gossip bag
        for driver in drivers:
            driver.meet(meeting_points[driver.current_stop])

        # check if all drivers know all other drivers
        all_know_others = all(( len(driver.knows) == len(routes) for driver in drivers ))

    if all_know_others:
        return True, clock.time
    else:
        return False, clock.time


if __name__ == '__main__':
    routes = [
        [3, 1, 2, 3],
        [3, 2, 3, 1],
        [4, 2, 3, 4, 5]
    ]
    knows, time = simulate(routes)
    print(knows, time)