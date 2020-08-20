// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Time: O(nlogn) can be improved to O(n) using unordered_map/ unordered_set
// Space: O(n) can be said O(1) as number of allowed chars is 26
// Prefix Sum based approach

class Solution {
public:
    int numSplits(string s) {
    	int n = s.size();
    	vector<int> fr(n, 1), bk(n, 1);
    	set<char> st;
    	map<char, int> freq;

    	for (auto ch: s)
    		freq[ch] += 1;

    	for (int i = 0; i < n; i += 1) {
    		st.insert(s[i]);
    		fr[i] = st.size();
    		bk[i] = freq.size();
    		freq[s[i]] -= 1;
    		if (freq[s[i]] == 0)
    			freq.erase(s[i]);
    	}

    	int cnt = 0;
    	for (int i = 0; i+1 < n; i += 1) {
    		if (fr[i] == bk[i+1])
    			cnt += 1;
    	}
        
        return cnt;
    }
};