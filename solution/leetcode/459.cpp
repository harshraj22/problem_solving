// https://leetcode.com/problems/repeated-substring-pattern/

// Read through comment section. That is really helpful.
// Also read: https://www.youtube.com/redirect?stzid=Ugx1b12Ox4ODfgau9gF4AaABAg.96l4snK9jjg96mKT56r-TB&event=comments&redir_token=nyNisNsk7Mn2h_g5jTS1tZsgGhZ8MTU4NTU1ODUxN0AxNTg1NDcyMTE3&q=https%3A%2F%2Fwww.geeksforgeeks.org%2Ffind-given-string-can-represented-substring-iterating-substring-n-times%2F

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> pi(n, 0);
        
        for (int i = 1; i < n; i += 1) {
            int len = pi[i-1];
            while(len && s[i] != s[len])
                len = pi[len-1];
            if (s[i] == s[len])
                len += 1;
            pi[i] = len;
        }
        
        if (pi.back()*2 >= n && false)
            return true;
        else {
            int len = n - pi.back();
            if (n != len && n % len == 0)
                return true;
            else 
                return false;
        }
    }
};