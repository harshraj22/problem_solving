// 	https://leetcode.com/problems/permutation-sequence/
// Basic Iteration with good logic
// Time: O(nlogn) Space: O(n)

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(10, 1);
    	for (int i = 1; i < fact.size(); i += 1)
    		fact[i] = i * fact[i-1];

    	vector<int> nums(n);
    	iota(nums.begin(), nums.end(), 1);

		set<int> st(nums.begin(), nums.end());

		for (int i = 0; i < n; i += 1) {
			int dist = n-1-i;
			for (auto val: st) {
				if (fact[dist] < k)
					k -= fact[dist];
				else {
					nums[i] = val;
					st.erase(val);
					break;
				}
			}
		}

		string s;
		for (auto num: nums)
			s += to_string(num);

		return s;
    }
};