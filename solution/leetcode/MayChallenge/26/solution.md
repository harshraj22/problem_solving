Problem: 
   - [Day 26](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/)

Tried: 
   - Used basic `Dynamic Programming`

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int numZeros = 0, numOnes = 0, length = 0;
        map<int, int> lastIndex = {{0, -1}};
        
        for (int i = 0; i < nums.size(); i += 1) {
            numZeros += (nums[i] == 0);
            numOnes += (nums[i] == 1);
            int diff = numZeros - numOnes;
            
            if (lastIndex.find(diff) != lastIndex.end()) {
                int cur_length = i - lastIndex[diff];
                length = max(length, cur_length);
            }   else {
                lastIndex[diff] = i;
            }
        }
        
        return length;
    }
};
```