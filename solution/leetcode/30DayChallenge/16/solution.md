Problem:
   - [Day16](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3301/)

Tried:
   - used `Matrix Chain Multiplication`
   - Small constraint was a hint :)

``` c++
class Solution {
public:
    #define N 102
    int dp[N][N];
    string str;
    
    bool covers(char c1, char c2) {
        // checks if chars 'c1' and 'c2' form a valid 
        // pair of paranthesis
        if (c1 == c2 && c1 == '*')
            return true;
        else if (c1 == c2)
            return false;
        else if (c1 == ')')
            return false;
        else if (c2 == '(')
            return false;
        return true;
    }
    
    bool check(int left, int right) {
        // returns if str[left, right] is valid
        
        // base case
        if (left > right)
            return true;
        else if (left == right)
            return str[left] == '*';
        else if (left + 1 == right) 
            return covers(str[left], str[right]);
        
        // if already calculated
        if (dp[left][right] != -1)
            return dp[left][right];
        
        dp[left][right] = 0;
        for (int i = left + 1; i < right; i += 1) 
            dp[left][right] += (check(left, i) && check(i+1, right));
        
        if (covers(str[left], str[right]))
            dp[left][right] += check(left+1, right-1);
        
        return dp[left][right];
    }
    
    bool checkValidString(string s) {
        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j < N; j += 1) {
                dp[i][j] = -1;
            }
        }
        
        str = s;
        int n = s.size();
        return check(0, n-1);        
    }
};
```