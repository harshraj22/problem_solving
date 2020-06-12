// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, left = 0, right = 0; 
        for (int i = 0; i < nums.size(); i += 1) {
            if (nums[i] == 0) {
                ans = max(ans, right-left);
                right = left = i+1;
            }
            else {
                right += 1;
            }
        }

        ans = max(ans, right-left);
        return ans;
    }
};