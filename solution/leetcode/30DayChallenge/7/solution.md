Problem:
   - [Day7](https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3289/)

Tried:
   - Basic `binary search`

``` c++
class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (auto it:arr) {
            if (binary_search(arr.begin(), arr.end(), it +1))
                ans += 1;
        }
        return ans;
    }
};
```