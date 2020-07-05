Problem: 
   - [Day 4](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/)

Tried: 
   - Simple `Bit Manipulation`


```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int _count = 0;
        for (int i = 0; i < 32; i += 1)
            _count += (((x & (1 << i)) ^ (y & (1 << i))) > 0 ? 1: 0);
    
        return _count;
    }
};
```
