Question [Link](https://leetcode.com/problems/powx-n/)

Time: O(logn)
Space: O(logn) -memory stack

Basic Idea Used: Modular Exponentiation (2^10 == 4^5 == 4 * (4^4)), the power decreases logarithmically

```c++
class Solution {
public:
    double myPow(double x, int n) {
        if (n == -1) 
            return myPow(1.0/x, -n);
        else if (n == 0)
            return 1;
        else if (n == 1)
            return x;
        if (n % 2 == 0) 
            return myPow(x*x, n/2);
        else 
            return x*myPow(x, n-1);
    }
};
```