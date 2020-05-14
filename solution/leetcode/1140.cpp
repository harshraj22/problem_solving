// https://leetcode.com/problems/stone-game-ii/

class Solution {
    int dp[101][101][101];
    vector<int> stones;

    int get(int l, int r, int m) {
        if (dp[l][r][m] != -1)
            return dp[l][r][m];
        else if (l > r) 
            return 0;
        else if (l == r)
            return dp[l][r][m] = stones[l];
        int total = accumulate(stones.begin()+l, stones.begin()+r+1, 0LL);
        for (int x = 1, sum = 0; x <= 2*m && l + x <= stones.size(); x += 1) {
            sum += stones[l + x - 1];
            dp[l][r][m] = max(dp[l][r][m], total - get(l + x, r, max(m, x)));
        }

        return dp[l][r][m];
    }

public:
    Solution() {
        for (int i = 0; i < 101; i += 1) {
            for (int j = 0;j < 101; j += 1) {
                for (int k = 0; k < 101; k += 1)
                    dp[i][j][k] = -1;
            }
        }
    }

    int stoneGameII(vector<int>& piles) {
        stones = piles;
        return get(0, (int)stones.size()-1, 1);
    }
};