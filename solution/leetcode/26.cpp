// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 1, cur = 1;
        while (cur < nums.size()) {
        	if (nums[cur] != nums[cur-1]) {
        		nums[index] = nums[cur];
        		index += 1;
        	}
        	cur += 1;
        }

        return index;
    }
};
