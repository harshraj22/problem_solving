Problem: 
   - [Day 22](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/)

Tried: 
   - Used simple use of `maps` or `dict`

```python
class Solution:
    def frequencySort(self, s: str) -> str:
        from collections import Counter
        freq = Counter(s)
        ordered = list(zip(freq.values(), freq.keys()))
        ordered.sort(key=lambda x: -x[0])
        # sum(ch for x, ch in ordered for count in range(x)): doesn't work
        #       as sum( ) doesn't support strings
        return ''.join(ch for x, ch in ordered for count in range(x))
```

```c++
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        vector<pair<int, char>> sorted;
        string ans;

        for (auto ch: s)
            freq[ch] += 1;
        for (auto it: freq)
            sorted.push_back({it.second, it.first});
        sort(sorted.begin(), sorted.end(), greater<pair<int,char>>());

        for (auto it: sorted) {
            while (it.first--) 
                ans += it.second;
        }
        
        return ans;
    }
};
```
