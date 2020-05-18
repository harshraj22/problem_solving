Problem: 
   - [Day 18](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/)

Tried: 
   - Used frequency counting using map with `sliding window` using `two pointers` 

```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // check if any permutation of s1 is substring of s2
        if (s1.size() > s2.size())  
            return false;

        map<char, int> freq;
        int left = 0, right = 0;

        for (auto ch: s1)
            freq[ch] += 1;
        while (right < s1.size()) {
            freq[s2[right]] -= 1;
            if (freq[s2[right]] == 0)
                freq.erase(s2[right]);
            right += 1;
        }

        if (freq.size() == 0)
            return true;

        while (right < s2.size()) {
            char first = s2[left], second = s2[right];
            freq[first] += 1;
            freq[second] -= 1;

            if (freq[first] == 0)
                freq.erase(first);
            if (freq[second] == 0)
                freq.erase(second);

            if (freq.size() == 0)
                return true;
            left += 1;
            right += 1;
        }

        return false;
    }
};
```