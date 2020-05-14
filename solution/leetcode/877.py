# https://leetcode.com/problems/stone-game/
# Read about functools.lru_cache 
# ^_^ this decorator is awesome

class Solution:
    from functools import lru_cache
    
    @lru_cache(maxsize=None)
    def solve(self, left, right):
        if left == right:
            return self.stones[left]
        total = sum(self.stones[left: right+1])
        return total - min(self.solve(left+1, right), self.solve(left, right-1))

    def stoneGame(self, piles: List[int]) -> bool:
        self.stones = piles
        total = self.solve(0, len(self.stones)-1)
        return total*2 > sum(piles)

'''
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
'''