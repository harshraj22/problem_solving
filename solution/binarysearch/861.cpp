// https://binarysearch.com/problems/Sublist-with-Largest-Min-Length-Product

// Two pointers 
// Time: O(n), space: O(1)

int solve(vector<int>& nums, int pos) {
	int ans = nums[pos];
	int left = pos, right = pos, n = nums.size(), lowest = nums[pos];

	while (left >= 0 || right < n) {
		if (left >= 0 && right < n)
			lowest = min(lowest, max(nums[left], nums[right]));
		else if (left >= 0)
			lowest = min(lowest, nums[left]);
		else if (right < n)
			lowest = min(lowest, nums[right]);

		while (left >= 0 && nums[left] >= lowest)
			left -= 1;
		while (right < n && nums[right] >= lowest)
			right += 1;

		ans = max(ans, lowest * (right-left-1));
	}

	return ans;
}



