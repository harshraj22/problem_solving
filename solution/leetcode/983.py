# https://leetcode.com/problems/minimum-cost-for-tickets/submissions/
# use of zip, @lru_cache makes solution cool

class Solution:
    from bisect import bisect_left
    from functools import lru_cache
    from math import inf

    @lru_cache(maxsize=None)
    def get(self, index):
        if index >= len(self.days):
            return 0
        return min(cost + self.get(bisect_left(self.days, self.days[index] + day)) for day, cost in zip([1, 7, 30], self.costs))

    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        self.days, self.costs = days, costs
        return self.get(0)

'''
class Solution {
    vector<int> dates, cost, dp;

    int get(int index) {
        if (index >= dp.size())
            return 0;
        else if (dp[index] != -1)
            return dp[index];
        dp[index] = INT_MAX;
        dp[index] = min(dp[index], cost[0] + get(lower_bound(dates.begin(), dates.end(), dates[index]+1) - dates.begin()));
        dp[index] = min(dp[index], cost[1] + get(lower_bound(dates.begin(), dates.end(), dates[index]+7) - dates.begin()));
        dp[index] = min(dp[index], cost[2] + get(lower_bound(dates.begin(), dates.end(), dates[index]+30) - dates.begin()));
        return dp[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dates = days;   cost = costs;
        dp.resize(days.size(), -1); 
        return get(0);
    }
};
'''