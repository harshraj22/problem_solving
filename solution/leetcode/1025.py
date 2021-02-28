# https://leetcode.com/problems/divisor-game/
# Solved again on Feb28, 2021

class Solution:
    from math import sqrt
    def __init__(self):
        self.cache = dict([(1, False), (2, True), (3, False)])
        
    def divisorGame(self, n: int) -> bool:
        if n in self.cache:
            return self.cache[n]
        for i in range(1, int(sqrt(n))+2):
            if n%i == 0 and not self.divisorGame(n-i):
                return self.cache.setdefault(n, True)
        return self.cache.setdefault(n, False)
        
'''
class Solution {
    map<int, int> cache;
public:
    Solution() {
        cache = {{1, false}, {2, true}, {3, false}};
    };
    
    bool divisorGame(int n) {
        if (cache.find(n) != cache.end())
            return cache[n];
        for (int i = 1; i*i <= n; i += 1)
            if (n % i == 0 && divisorGame(n-i) == false)
                return cache[n] = true;
        return cache[n] = false;
    }
};
'''