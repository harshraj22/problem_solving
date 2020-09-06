// https://leetcode.com/problems/sliding-window-maximum/
// Time: O(n) each element is pushed/poped in deque only once, Space: O(k)

class Solution {
	void insert(deque<pair<int, int>> &q, int val, int index) {
		while (q.empty() == false && q.back().first < val)
			q.pop_back();
		q.push_back({val, index});
	}

	void remove(deque<pair<int, int>> &q, int val, int index) {
		if (q.empty() || q.front().second > index)
			return;
		else if (q.front().second == index)
			q.pop_front();
	}

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	deque<pair<int, int>> q;
    	vector<int> ans;
    	if (nums.size() < k)
    		return {};

    	for (int i = 0; i < k; i += 1) 
    		insert(q, nums[i], i);
    	ans.push_back(q.front().first);

    	for (int i = k; i < nums.size(); i += 1) {
    		remove(q, nums[i-k], i-k);
    		insert(q, nums[i], i);
    		ans.push_back(q.front().first);
    	}

    	return ans;
    }
};