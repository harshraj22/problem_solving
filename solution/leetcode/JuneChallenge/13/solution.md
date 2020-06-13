Problem: 
   - [Day 13](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/)

Tried: 
   - Simple `Dynamic Programming`
   - Catch was to sort it (see Erritcho's DP playlists: Exchange Arguments video)


```c++
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), index = n-1;
        vector<pair<int, int>> dp(n);
        sort(nums.begin(), nums.end());

        for (int i = n-1; i >= 0; i -= 1) {
            dp[i] = {1, -1};
            for (int j = i+1; j < n; j += 1) {
                if (nums[j] % nums[i] == 0 && dp[j].first >= dp[i].first) {
                    dp[i] = {dp[j].first+1, j};
                } 
            }
            if (dp[i].first > dp[index].first)
                index = i;
        }      

        vector<int> subset;
        while (index != -1) {
            subset.push_back(nums[index]);
            index = dp[index].second;
        }

        return subset;
    }
};
```