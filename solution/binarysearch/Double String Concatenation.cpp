// https://binarysearch.com/problems/Double-String-Concatenation

int n;
vector<vector<int>> dp;
#define all(x) x.begin(), x.end()

int min_dist(string s1, int i, string s2, int j) {
    // cout << s1 << ' ' << s2 << endl;
    if (i == s1.size())
        return (int)s2.size() - j;
    else if (j == s2.size())
        return (int)s1.size() - i;
    else if (dp[i][j] != -1)
        return dp[i][j];
    
    if (s1[i] == s2[j])
        return dp[i][j] = min_dist(s1, i+1, s2, j+1);
    return dp[i][j] = 1 + min({min_dist(s1, i+1, s2, j), min_dist(s1, i, s2, j+1), min_dist(s1, i+1, s2, j+1)});
}

void init() {
    for (int i = 0; i < n; i += 1)
        fill(all(dp[i]), -1);
}

int solve(string s) {
    if (s.size() < 2)
        return s.size();
    n = s.size();
    // intialize dp table
    dp = vector<vector<int>> (n, vector<int> (n, -1));
    int ans = n + 1;
    for (int i = 0; i < n; i += 1) {
        init();
        ans = min(ans, min_dist(s.substr(0, i+1), 0, s.substr(i+1), 0));
    }

    return ans;
    // return recur(0, n-1, s);    
}