Problem:
   - [Day23](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/)

Tried:
   - Observation based `Bitwise`

``` c++
class Solution {
public:
    bool isSet(long long int num, int bit) {
        return num & (1LL << bit);
    }
    
    int rangeBitwiseAnd(long long int m, long long int n) {
        long long int ans = 0;
        for (int i = 40; i >= 0; i -= 1) {
            if (isSet(m, i) && isSet(n, i)) 
                ans = ans | (1LL << i);
            else if (isSet(m, i) != isSet(n, i))
                break;
        }
        return ans;
    }
};
```