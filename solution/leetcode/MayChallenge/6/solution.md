Problem: 
   - [Day 6](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/)

Tried: 
   - Simple use of `Dictonary` of `Hash Map`
   - A more optimized way is to use `Boyer-Moore Voting Algorithm`

```python
# Boyer-Moore Voting Algorithm
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        element, freq = 0, 0
        for num in nums:
            freq += 1 if element == num else -1
            # update if freq < 0
            if freq < 0:
                element, freq = num, 1
        return element
```
        
```python
class Solution:
    from collections import Counter
    
    def majorityElement(self, nums: List[int]) -> int:
        freq = Counter(nums)
        return freq.most_common(1)[0][0]
```

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq; int ans = 0;
        for (auto it: nums) {
            freq[it] += 1;
            if (freq[it] > freq[ans])
                ans = it;
        }
        
        return ans;
    }
};
```