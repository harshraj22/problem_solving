Problem: 
   - [Day 8](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/)

Tried: 
   - Standard `bitset`


```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (__builtin_popcount(n) == 1) && (n > 0);
    }
};
```