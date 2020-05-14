// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
    // pair<sum, max>
    int n; pair<int, int> dp[41][41];
    vector<int> nums;

    pair<int, int> get(int left, int right) {
        if (dp[left][right] != make_pair(-1, -1))
            return dp[left][right];
        else if (left == right) 
            return dp[left][right] = {0, nums[left]};
        dp[left][right] = {INT_MAX, *max_element(nums.begin()+left, nums.begin()+right+1)};

        for (int i = left; i < right; i += 1) {
            auto l = get(left, i), r = get(i+1, right);
            auto sum = l.first + r.first;
            dp[left][right].first = min(dp[left][right].first, l.first + r.first + l.second*r.second);
        }

        return dp[left][right];
    }

public:
    Solution() {
        for (int i = 0; i < 41; i += 1) {
            for (int j = 0; j < 41; j += 1)
                dp[i][j] = {-1, -1};
        }
    }

    int mctFromLeafValues(vector<int>& arr) {
        nums = arr;
        return get(0, (int)nums.size()-1).first;
    }
};