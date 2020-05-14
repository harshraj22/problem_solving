// https://leetcode.com/problems/stone-game/

class Solution {
    vector<int> stones;
    // dp[i][j] stores the max sum player starting can make
    // if the stones are given stones[i:j+1]
    int dp[501][501];

    int get(int left, int right) {
        if (dp[left][right] != -1)
            return dp[left][right];
        else if (left == right)
            return dp[left][right] = stones[left];
        int sum = accumulate(stones.begin()+left, stones.begin()+right+1, 0LL);

        dp[left][right] = max(sum - get(left+1, right), sum - get(left, right-1));
        return dp[left][right];
    }

public:
    Solution() {
        for (int i = 0; i < 501; i += 1) {
            for (int j = 0; j < 501; j += 1) 
                dp[i][j] = -1;
        }
    }

    bool stoneGame(vector<int>& piles) {
        stones = piles;
        int sum = get(0, (int)stones.size()-1);
        return sum*2 > accumulate(piles.begin(), piles.end(), 0LL);
    }
};