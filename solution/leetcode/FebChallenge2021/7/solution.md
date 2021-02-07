Problem:
   - [Day7](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3631/)

Tried:
   - Simple Binary Search

``` cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
    	int n = s.size();
    	vector<int> indices, ans(n);

    	// store the indices where 'c' occurs
    	for (int i = 0; i < n; i += 1) {
    		if (s[i] == c)
    			indices.push_back(i);
    	}

    	// create the distance array
    	for (int i = 0; i < n; i += 1) {
    		// smallest dist where 'c' occurs in 's'
    		auto it = lower_bound(indices.begin(), indices.end(), i);
    		int before, after;

    		// if there's no 'c' after index 'i' in 's'
    		// set value of 'after' to a large const
    		if (it == indices.end())
    			after = 4*n;
    		else	// else calc the dist
    			after = *it - i;

    		// if there is no 'c' before index 'i' in 's'
    		// set value of 'before' to a large const
    		if (it == indices.begin())
    			before = 4*n;
    		else {
	    		it = prev(it);
	    		before = i - *it;
    		}

    		// store the min of the two as ans
    		ans[i] = min(before, after);
    	}
        
        return ans;
    }
};
```