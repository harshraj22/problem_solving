# https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet:
    import random

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # map of (key, index in list)
        self.map = dict()
        
        # list of keys for random selection
        self.keys = []
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.map:
            return False
        index = len(self.keys)
        self.map[val] = index
        self.keys.append(val)
        return True
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.map:
            return False
        index = self.map[val]
        del self.map[val]
        
        if index+1 != len(self.keys):
            var = self.keys[-1]
            self.keys[index] = self.keys[-1]
            self.map[var] = index
        self.keys = self.keys[:-1]
        # print('removing. ', self.map)
        return True
        

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return random.choice(self.keys)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()