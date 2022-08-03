# https://leetcode.com/problems/count-primes/

class Solution:
    def countPrimes(self, n: int) -> int:
        is_prime = [True for _ in range(n)]
        is_prime[:2] = [False, False]
        
        for i in range(2, n):
            if is_prime[i]:
                for j in range(i*2, n, i):
                    is_prime[j] = False
        
        return sum(is_prime)
        