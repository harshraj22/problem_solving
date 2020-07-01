Problem: 
   - [Day 1](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/)

Tried: 
   - Simple `Brute Force`.


```c++
class Solution {
public:
    int arrangeCoins(int n) {
        int _count = 0;
        for (int i = 1; i <= n; i += 1) {
            _count += 1;
            n -= i;
        }
        
        return _count;
    }
};
```
