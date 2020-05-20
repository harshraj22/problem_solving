// https://leetcode.com/problems/coin-change/

class Solution {
    unordered_map<int, int> cache;
    vector<int> denominations;
    const static int LIMIT = 1e7;

    int get(int amount) {
        if (cache.find(amount) != cache.end())
            return cache[amount];
        else if (amount < 0)
            return cache[amount] = LIMIT;
        else if (amount == 0)
            return cache[amount] = 0;
        int ans = LIMIT;
        for (int i = 0; i < denominations.size(); i += 1) {
            ans = min(ans, 1 + get(amount - denominations[i]));
        }

        return cache[amount] = ans;
    }

public:

    int coinChange(vector<int>& coins, int amount) {
        denominations = coins;
        int ans = get(amount);
        
        if (ans >= LIMIT) ans = -1;
        return ans;
    }
};