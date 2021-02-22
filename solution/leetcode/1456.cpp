// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, l = 0, r = 0, _cnt = 0;

        string vowel = "aeiou";

        while (r < s.size()) {
        	if (vowel.find(s[r]) != string::npos)
	        	_cnt += 1;

        	while (r-l+1 > k) {
        		if (vowel.find(s[l]) != string::npos)
        			_cnt -= 1;
        		l += 1;
        	}

        	ans = max(ans, _cnt);
        	r += 1;
        }

        return ans;
    }
};