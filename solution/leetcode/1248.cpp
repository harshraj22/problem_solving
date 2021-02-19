// https://leetcode.com/problems/count-number-of-nice-subarrays/
// two pointer based solution


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> indexes = {-1};
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i += 1) {
        	if (nums[i] % 2 == 1)
        		indexes.push_back(i);
        }

        indexes.push_back(n);

        for (int i = 1; i+k < indexes.size(); i += 1) {
        	int left = indexes[i] - indexes[i-1];
        	int right = indexes[i+k] - indexes[i+k-1];
        	ans += left * right;
        }

        return ans;

    }
};