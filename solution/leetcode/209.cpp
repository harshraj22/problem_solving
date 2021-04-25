// https://leetcode.com/problems/minimum-size-subarray-sum/

#define all(x) x.begin(), x.end()

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // create a prefix sum
        vector<int> pref(1);
        for (auto num: nums) 
            pref.push_back(num + pref.back());

        int ans = nums.size() + 2, n = nums.size();

        for (int i = 1; i <= n; i += 1) {
            int req = pref[i-1] + target;
            // find index whose val is >= req
            int index = lower_bound(all(pref), req) - pref.begin();
            if (index <= n)
                ans = min(ans, index-i+1);
        }

        if (ans > nums.size()) ans = 0;
        return ans;
    }
};