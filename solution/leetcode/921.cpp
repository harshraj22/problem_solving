// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Time: O(n), Space: O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {
    	int n = s.size(), _count = 0, ans = 0;

    	// when the seq becomes invalid, add corresponding
    	// parenthesis and make it valid
    	for (auto ch: s) {
    		_count += (ch == '('? 1 : -1);
    		if (_count < 0) {
    			ans += 1;
    			_count = 0;
    		}
    	}
      
    	return ans + abs(_count);
    }
};