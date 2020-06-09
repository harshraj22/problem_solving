Problem: 
   - [Day 9](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/)

Tried: 
   - Standard `Recursion`, similar to `Dp`


```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0)
            return true;
        else if (t.size() == 0)
            return false;
        if (s[0] == t[0])
            return isSubsequence(s.substr(1), t.substr(1));
        return isSubsequence(s, t.substr(1));      
    }
};
```