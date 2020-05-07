// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
    // pair of (index, length)
    pair<int, int> ans; string s;
    vector<vector<int>> dp;
    
    bool recur(int left, int right) {
        if (left > right)
            return false;
        else if (left == right) {
            if (ans.second < 1) 
                ans = make_pair(left, 1);
            return true;
        }
        else if (dp[left][right] != -1) 
            return dp[left][right];
        else if (s[left] != s[right])
            dp[left][right] = false;
        else 
            dp[left][right] = (left+1 < right) ? recur(left+1, right-1): true;
        recur(left+1, right);   recur(left, right-1);
        if (ans.second < right-left+1 && dp[left][right])
            ans = make_pair(left, right-left+1);
        
        return dp[left][right];
    }
    
public:
    string longestPalindrome(string str) {
        int n = str.size(); s = str;
        dp.resize(n);   ans = {0, 0};
        for (auto &it: dp) {
            it.resize(n);
            fill(it.begin(), it.end(), -1);
        }
        recur(0, n-1);
        return s.substr(ans.first, ans.second);
    }
};