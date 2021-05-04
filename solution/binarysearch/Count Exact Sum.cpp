// https://binarysearch.com/problems/Count-Exact-Sum

#define ll long long int
vector<vector<ll>> dp;
int n, mod = 1e9 + 7;

void print() {
    for (auto row: dp) {
        for (auto i: row)
            cout << i << ' ';
        cout << '\n';
    }
}

int recur(int r, int sum, vector<int> &nums) {
    if (r < 0 && sum > 0) return 0;
    else if (sum < 0) return 0;
    else if (sum == 0) return 1;
    else if (dp[r][sum] != -1) return dp[r][sum];
    dp[r][sum] = (recur(r-1, sum-nums[r], nums) + recur(r-1, sum, nums)); // % mod;
    if (dp[r][sum] > mod)
        dp[r][sum] %= mod;
    return dp[r][sum];
}

int solve(vector<int>& nums, int k) {
    n = nums.size();
    dp = vector<vector<ll>> (n, vector<ll> (k+1, -1));
    // print();
    int x = recur(n-1, k, nums);
    // print();
    return x;
}