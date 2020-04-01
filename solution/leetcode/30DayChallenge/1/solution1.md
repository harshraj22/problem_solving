Problem:
   - [Day1](https://leetcode.com/explore/other/card/30-day-leetcoding-challenge/528/week-1/3283/)

Tried: 
   - ```for_each``` function from ```algorithm``` library.
   - ```labmda``` functions in c++.

``` c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        auto Xor = [&](int i)->void{ans ^= i;};
        for_each(nums.begin(), nums.end(), Xor);
        return ans;
    }
};

```

Tried:
   - ```Reduce``` function from ```functools```

``` python
from functools import reduce

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x,y: x^y, nums)

```