Problem:
   - [Day11](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3297/)

Tried:
   - Solution using `multiset`

``` c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> mltst = {stones.begin(), stones.end()};
        while(mltst.size() > 1) {
            auto it = mltst.rbegin();
            int y = *it;    it ++;
            int x = *it;     

            // You can't use reverse iterator for multiset.erase()
            // .base() converts a reverse iterator to a forward iterator
            //      but points to the next position, so ++it, before .base()
            mltst.erase((++it).base());
            mltst.erase(prev(mltst.end()));
            
            if (x != y) {
                mltst.insert(y - x);   
            }
        }   
        
        if (!mltst.empty())
            return *mltst.begin();
        return 0;
    }
};
```

   - `Priority queue` based solution

``` c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // the default implementation is priority_queue using max heap
        // so .top() gives the max element present
        priority_queue<int> pq = {stones.begin(), stones.end()};
        while(pq.size() > 1) {
            int y = pq.top();   pq.pop();
            int x = pq.top();   pq.pop();
            if (x != y) 
                pq.push(y - x);
        }
        
        if (pq.empty())
            return 0;
        return pq.top();
    }
};
```