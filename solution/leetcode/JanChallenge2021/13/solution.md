Problem:
   - [Day13](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3602/)

Tried:
   - operations over multiset and greedy

``` cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());
        multiset<int> mltst = {people.begin(), people.end()};
        int num = 0;

        for (auto p: people) {
            // if already part of some other boat
            if (mltst.find(p) == mltst.end())
                continue;

            num += 1;

            // remove it from set
            mltst.erase(mltst.find(p));

            // try to take the largest weight such that the sum is
            // less than the 'limit'
            int req_max = limit - p;
            if (req_max < 0) 
                continue;

            auto it = mltst.upper_bound(req_max);
            // take prev(it) if available (coz we used upper_bound)
            if (mltst.empty() || it == mltst.begin())
                continue;

            it = prev(it);
            mltst.erase(it);
        }

        return num;
    }
};
```