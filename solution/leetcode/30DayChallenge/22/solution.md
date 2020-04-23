Problem:
   - [Day22](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3307/)

Tried:
   - Simple `Prefix Sum`

``` c++
class Solution {
public:
    #define ll long long int
    
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> freq {{0, 1}};
        int ans = 0;    ll pref = 0;
        for (auto it: nums) {
            pref += it;
            ans += freq[pref-k];
            freq[pref] += 1;
        }
        
        return ans;
    }
};
```