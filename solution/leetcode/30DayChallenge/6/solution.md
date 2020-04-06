Problem:
   - [Day6](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3288/)

Tried:
   - Simple use of `std::map`

``` c++
// Two strings are anagrams, iff on sorting, they produce same string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        // mp[str] stores index (in 'ans') of the annagram of 'str'
        map<string, int> mp;
        
        for (auto str:strs) {
            string cur = str;
            sort(cur.begin(), cur.end());
            
            if (mp.find(cur) == mp.end()) {
                mp[cur] = mp.size();
                ans.resize(1+ans.size());
            }
            ans[mp[cur]].push_back(str);            
        }
        
        return ans;
    }
};
```