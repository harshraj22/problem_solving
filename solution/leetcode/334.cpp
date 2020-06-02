// https://leetcode.com/problems/increasing-triplet-subsequence/
// Good Deque Based solution
// Time: O(n) space: O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // if increasing seq of len:3 is formed, we return true
        // dq stores any increasing seq
        deque<int> dq;
        int n = nums.size();
        for (int i = n-1; i >= 0; i -= 1) {
            if (dq.empty())
                dq.push_back(nums[i]);
            else if (dq.size() == 1) {
                if (nums[i] > dq.front())
                    dq.front() = nums[i];
                else if (nums[i] < dq.front())
                    dq.push_front(nums[i]);
            }
            else if (dq.size() == 2) {
                if (nums[i] < dq.front())
                    return true;
                else if (nums[i] < dq.back())
                    dq.front() = nums[i];
                else // think about it why, use the given test case
                    dq.back() = nums[i];
            }
        }

        return false;
    }
};


// [4,5,6,3,4]