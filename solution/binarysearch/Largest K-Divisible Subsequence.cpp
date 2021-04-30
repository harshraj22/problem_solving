// https://binarysearch.com/problems/Largest-K-Divisible-Subsequence


vector<vector<int>> dp;
int k, _min = -1e6;

void print() {
    for (auto it: dp) {
        for (auto ele: it)
            cout << ele << ' ';
        cout << '\n';
    }
}

int recur(int index, int rem, vector<int> &nums) {
    cout << index << ' ' << rem << '\n';
    // if (rem == 0) rem = 10;
    if (index < 0) return _min;
    else if (dp[index][rem] != -1) return dp[index][rem];
    if (index == 0) {
        if (nums[index] % k == rem)
            return dp[index][rem] = nums[index];
        else if (rem == 0) return dp[index][rem] = 0;
        return _min;
    }

    int cur_rem = (k - nums[index] % k) % k;
    int req_rem = (k + cur_rem + rem) % k;
    dp[index][rem] = recur(index-1, rem, nums);

    dp[index][rem] = max(dp[index][rem], recur(index-1, req_rem % k, nums) + nums[index] + req_rem / k);

    if (req_rem == 0) dp[index][rem] = max(dp[index][rem], nums[index]);
    return dp[index][rem];
}

int solve(vector<int>& nums, int _k) {
    int n = nums.size();
    k = _k;
    dp = vector<vector<int>> (n, vector<int> (11, -1));

    int val = max(0, recur(n-1, 0, nums));
    print();
    return val;
}