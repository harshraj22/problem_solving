// https://leetcode.com/problems/non-overlapping-intervals/
// Seriously, it was tough to converge to idea that it required `interval scheduling` technique

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return 0;
        
        auto cmp = [](vector<int> A, vector<int> B)->bool{
            if (A[1] != B[1])
                return A[1] < B[1];
            return A[0] > B[0];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int> > ans = {intervals.front()};
        
        auto intersects = [](vector<int> A, vector<int> B)->bool{
            if (A[1] <= B[0] || A[0] >= B[1])
                return false;
            return true;
        };
        
        for (int i = 1; i < intervals.size(); i += 1) {
            if (!intersects(ans.back(), intervals[i]))
                ans.push_back(intervals[i]);
        }
        
        return (int)intervals.size() - ans.size();
    }
};