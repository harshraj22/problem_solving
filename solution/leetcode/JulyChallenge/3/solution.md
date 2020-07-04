Problem: 
   - [Day 3](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/)

Tried: 
   - Simple `BFS` based solution


```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int> nums = {1, 2, 3, 4, 5};
        set<long long int> st = {2, 3, 5};
        if (n <= nums.size())
            return nums[n-1];
        nums = vector<long long int>();
        
        n -= 1;
        while (n--) {
            long long int nextNum = *st.begin();
            st.erase(st.begin());
            if (binary_search(nums.begin(), nums.end(), nextNum))
                continue;
            nums.push_back(nextNum);
            st.insert(nextNum*2);
            st.insert(nextNum*3);
            st.insert(nextNum*5);        
        }
        
        return nums.back();
    }
};
```
