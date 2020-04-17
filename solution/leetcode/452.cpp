// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Another `Sweep Line` based solution

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() < 2)
            return points.size();
        
        auto cmp = [](vector<int> A, vector<int> B)->bool{
            if (A[0] != B[0])
                return A[0] < B[0];
            return A[1] < B[1];                
        };
        sort(points.begin(), points.end(), cmp);
        
        int count = 0, last = -1;
        for (auto it: points) {
            if (it[0] > last) {
                count += 1;
                last = it[1];
            }   else {
                last = min(last, it[1]);
            }
        }
        
        return count;
    }
};