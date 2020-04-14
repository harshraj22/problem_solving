Problem:
   - [Day2](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/)

Tried: 
   - ```Two pointers``` O(n) space and time

``` c++
class Solution {
public:
    int shift(int ptr, int dir, int amt, int len) {
    	// shifts the pointer (ptr) in the given direction (dir)
    	// with given amount (amt) 
        if (!dir) 
            ptr = (ptr + amt) % len;
        else 
            ptr = (len + ptr - amt) % len;
        return ptr;
    }
    
    string stringShift(string s, vector<vector<int>>& Shift) {
        int n = s.size(), m = 2*n, left = 0, right = n-1;
        string str = s + s, ans;
        
        for (auto it:Shift) {
            int dir = it[0], amt = it[1];
            left = shift(left, dir, amt, m);
            right = shift(right, dir, amt, m);
        }
        
        while(left != right) {
            ans += str[left];
            left = (left + 1) % m;
        }
        
        ans += str[right];
        
        return ans;
    }
};
```
