// https://binarysearch.com/problems/Lowest-Sum-of-Pair-Larger-than-Target

#define all(x) x.begin(), x.end()

int solve(vector<int>& nums, int target) {
    sort(all(nums));

    int ans = 1e7;
    for (int i = 0; i < nums.size(); i += 1) {
        int cur = nums[i];
        int req = target - cur;
        // find the smallest num in nums which is > req
        auto it = upper_bound(all(nums), req);
        if (i == it - nums.begin())
            it = next(it);
        if (it == nums.end())
            continue;
        ans = min(ans, cur + *it);   
    }

    return ans;
}