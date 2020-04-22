// https://leetcode.com/problems/palindromic-substrings/
// Basic Two Pointers approach O(n2)
// Can be made better using Manacher's algo

class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size(), n = s.size();
        
        // odd length
        for (int i = 1; i < n; i += 1) {
            int len = 1;
            while(i-len >= 0 && i+len < n && s[i-len] == s[i+len])
                len += 1;
            ans += (len-1);
        }
        
        // even length 
        for (int low = 0; low+1 < n; low += 1) {
            int start = low, end = low + 1;
            while(start >= 0 && end < n && s[start] == s[end]) {
                start -= 1;   end += 1;
            }
            
            ans += (end - start + 1)/2 - 1;
        }
        
        return ans;
    }
};