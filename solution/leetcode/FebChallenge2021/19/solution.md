Problem:
   - [Day19](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3645/)

Tried:
   - Simple stack based solution

``` cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
    	int n = s.size();
        char c = '#';
    	stack<int> stk;

    	for (int i = 0; i < n; i += 1) {
    		if (isalpha(s[i]))
    			continue;
    		else if (s[i] == '(')
    			stk.push(i);
    		else if (stk.empty())
    			s[i] = c;
    		else 
    			stk.pop();
    	}

    	while (!stk.empty()) {
    		int i = stk.top();
    		stk.pop();
    		s[i] = c;
    	}

    	string ss;
    	for (auto ch: s) 
    		if (ch != '#')
    			ss.push_back(ch);

    	return ss;
    }
};
```