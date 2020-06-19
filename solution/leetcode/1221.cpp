// https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        int _count = 0, open = 0;
        for (auto ch: s) {
        	open += (ch == 'L'? 1: -1);
        	if (open == 0)
        		_count += 1;
        }

	    return _count;
    }
};