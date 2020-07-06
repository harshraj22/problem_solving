Problem: 
   - [Day 5](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/)

Tried: 
   - Simple `Brute Force`


```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();
        vector<int> sum(n, 0);
        for (int i = n-1; i >= 0; i -= 1) {
            int cur = digits[i] + carry;
            carry = cur/ 10;
            sum[i] = cur % 10;
        }
        
        if (carry > 0)
            sum.insert(sum.begin(), 1);
        
        return sum;
    }
};
```
