Problem: 
   - [Day 8](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/)

Tried: 
   - Simple `Binary Search`


```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i += 1) {
            for (int j = i+1; j < n; j += 1) {
                if (binary_search(nums.begin()+j+1, nums.end(), -nums[i] - nums[j]))
                    st.insert({nums[i], nums[j], -nums[i]-nums[j]});
                while (j+1 < n && nums[j] == nums[j+1])
                    j += 1;
            }
        }
        
        return vector<vector<int>> (st.begin(), st.end());
    }
};
```
