Problem:
   - [Day19](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3609/)

Tried:
   - O(n2) dp to store palindromes

``` cpp
class Solution {
    vector<vector<int>> table;
    // table[i][j] stores if ss[i:j+1] is a palindrome
    int n;
    string ss;

    int dp(int l, int r) {
        if (l > r)
            return 0;
        // out of bounds
        else if (l < 0 || r >= ss.size())
            return 0;
        else if (l == r) 
            return table[l][r] = 1;
        else if (l+1 == r)
            return table[l][r] = (ss[l] == ss[r]);
        else if (table[l][r] != -1)
            return table[l][r];
        dp(l+1, r);
        dp(l, r-1);

        return table[l][r] = (ss[l] == ss[r]) && dp(l+1, r-1);
    }
public:
    string longestPalindrome(string s) {
        ss = s;
        n = s.size();
        table = vector<vector<int>> (n, vector<int>(n, -1));

        dp(0, n-1);
        s = "";

        for (int i = 0; i < n; i += 1) {
            for (int j = i; j < n; j += 1) {
                if (dp(i, j) && s.size() < j-i+1)
                    s = ss.substr(i, j-i+1);
            }
        }

        return s;
    }
};
```