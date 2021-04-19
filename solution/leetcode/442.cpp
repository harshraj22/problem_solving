// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/
// Read about: How to store 2 numbers at one place from gfg
// solved again on April 19th, 2021

/*
Basic Idea:
    Let mod > *max_element(all(nums))
    at any index, 'num', to store 'val' use:
        nums[index] = num + mod*val
    to retrive num, use:
        num = nums[index] % mod
    to retrive val, use:
        val = nums[index] / mod
    Now it is clear why mod > *max_element(all(nums)) is required
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int n = nums.size(), mod = n;
        vector<int> duplicates;

        // the second number stored at 'index' denotes frequency of 'index' in nums

        // for each number, go to the index it represents
        for (auto num: nums) {
            num = num % mod;
            int freq = nums[num] / mod;
            // increase the frequency there
            nums[num] = nums[num] % mod + mod*(freq + 1);
        }

        for (int i = 0; i < n; i += 1) {
            // for each number represented by its index
            int freqOfIndex = nums[i] / mod;
            // if freq of number is >= 2
            if (freqOfIndex >= 2)
                duplicates.push_back(i);
        }

        // if required, revert back original array 'nums'

        return duplicates;
    }
};
