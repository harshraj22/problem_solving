Problem: 
   - [Day 13](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/)

Tried: 
   - Used `Stack`

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk; stk.push(num[0]);
        string ans; int n = num.size();
        
        for (int i = 1; i < n; i += 1) {
            while (!stk.empty() && num[i] < stk.top() && k > 0) {
                stk.pop(); k -= 1;
            }
            stk.push(num[i]);
        }
        
        while (!stk.empty()) {
            if (k > 0)
                k -= 1;
            else 
                ans += stk.top();
            stk.pop();
        }

        while (!ans.empty() && ans.back() == '0')
            ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0": ans;
    }
};
```