Problem:
   - [Day9](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/)

Tried:
   - Awesome `Stack` Based Solution

``` c++
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sts, stt;
        for (auto it:s) {
            if (it == '#') {
                if (!sts.empty())
                    sts.pop();
            }
            else {
                sts.push(it);
            }
        }
        
        for (auto it:t) {
            if (it == '#') {
                if (!stt.empty()) {
                    stt.pop();
                }
            }
            else 
                stt.push(it);
        }
        return sts == stt;
    }
};
```

Follow up:
   - O(N) time and O(1) space using `Two Pointers` Technique

``` c++
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int left = 0, right = 0;
        while(right < S.size()) {
            if (S[right] == '#') {
                left = max(0, left-1);
            } else {
                S[left] = S[right];
                left += 1;
            }
            right += 1;
        }
        
        S = S.substr(0, left);
        
        right = left = 0;
        while(right < T.size()) {
            if (T[right] == '#') {
                left = max(left-1, 0);
            }   else {
                T[left] = T[right];
                left += 1;
            }
            right += 1;
        }
        
        T = T.substr(0, left);
        
        return S == T;
    }
};
```