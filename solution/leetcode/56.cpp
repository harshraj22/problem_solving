// https://leetcode.com/problems/merge-intervals/
// yet another Sweep Line Problem

class Solution {
public:
    #define pi pair<int, int>
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int first = -1, last = -1;
        vector<vector<int> > ans;
        
        sort(intervals.begin(), intervals.end());
        
        for (auto it: intervals) {
            pi cur = {it[0], it[1]};
            if (cur.first > last) {
                if (first >= 0 && last >= 0)
                    ans.push_back({first, last});
                first = cur.first;
            }
            
            last = max(last, cur.second);
        }
        
        if (first >= 0 && last >= 0)
            ans.push_back({first, last});

        return ans;
    }
};