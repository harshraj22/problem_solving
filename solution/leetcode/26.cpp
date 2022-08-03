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


/*

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        NOT_EXIST = -102
        
        for index, num in enumerate(nums[1:], 1):
            if num == nums[index-1]:
                nums[index-1] = NOT_EXIST
        
        left, right = 0, 1
        while right < len(nums):
            while left < right and nums[left] != NOT_EXIST:
                left += 1
            while right < len(nums) and nums[right] == NOT_EXIST:
                right += 1
            if right < len(nums):
                nums[left], nums[right] = nums[right], nums[left]
            right += 1
        
        return left+1

*/
