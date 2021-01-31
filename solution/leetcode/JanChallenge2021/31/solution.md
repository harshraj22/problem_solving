Problem:
   - [Day31](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3623/)

Tried:
   - Simple Logic

``` cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      // if sorted in decreasing order, sort in increasing and return
      if (is_sorted(nums.begin(), nums.end(), greater<int>())) {
        sort(nums.begin(), nums.end());
        return;
      }

      int n = nums.size();
      map<int, int> st;

      for (int i = n-1; i >= 0; i -= 1) {
        // if there is an element in st larger than current element
        // swap the two, and sort nums[i+1:]
        if (st.upper_bound(nums[i]) == st.end())
          st[nums[i]] = i;
        else {
          int index = st.upper_bound(nums[i])->second;
          swap(nums[i], nums[index]);
          sort(nums.begin()+i+1, nums.end());
          return;
        }
      }
    }
};
```