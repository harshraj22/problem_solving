// https://leetcode.com/problems/create-target-array-in-the-given-order/

/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    let ans = [];
    for (let i = 0; i < index.length; i += 1) {
        ans.splice(index[i], 0, nums[i]);
    }
    
    return ans;
};

/* 
# python3
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for num, position in zip(nums, index):
            target.insert(position, num)
            
        return target

*/