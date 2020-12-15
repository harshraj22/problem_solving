# Probably a better naming convention could have been used.

class Driver:
    def __init__(self, driver_id, route):
        self._route = route
        self._driver_id = driver_id
        self.position = 0
        self._knows = set([self._driver_id])

    @property
    def driver_id(self):
        return self.driver_id

    @property
    def current_stop(self):
        return self._route[self.position]

    def move_next(self):
        self.position = (self.position + 1) % len(self._route)

    def meet(self, other_drivers):
        self._knows = self._knows | other_drivers
    
    @property
    def knows(self):
        return self._knows