// https://leetcode.com/problems/jump-game/
// Time: O(n), Space: O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1, 0);

        // pref[i] = num of true in nums[i]..nums[n-1] (prefix sum)
        pref[n-1] = 1;

        for (int i = n-2; i >= 0; i -= 1) {
        	int right = 1 + min(n-1, i + nums[i]);
        	bool possible = pref[i+1] - pref[right];

        	pref[i] = pref[i+1] + possible;
        }

        return pref[0] - (n > 1 ? pref[1]: 0);
    }
};

/*
Time: O(n), Space: O(1)

from math import inf

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last_possible_index = inf
        n = len(nums)
        for i in range(n-1, -1, -1):
            if nums[i] + i >= min(n-1, last_possible_index):
                last_possible_index = i
        return last_possible_index == 0

*/
