Problem:
   - [Day13](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3298/)

Tried:
   - Solution using `maps`

``` c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int numZeros = 0, numOnes = 0, length = 0;
        // lastIndex[i] stores the last index where difference
        // between (countOfZeros and countOfOnes) was 'i'
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
