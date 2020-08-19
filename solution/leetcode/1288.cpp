// https://leetcode.com/problems/remove-covered-intervals/
// Time: O(nlogn) Space: O(n)
// Sorting with custom comparator

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        	if (a[0] != b[0])
        		return a[0] < b[0];
        	return a[1] > b[1];
        });

        int cnt = 0;
        set<int> last = {-1};
        for (auto v: intervals) {
        	while (!last.empty() && v[0] >= *last.begin())
        		last.erase(last.begin());
        	if (last.empty() || *last.rbegin() < v[1])
        		cnt += 1;
        	last.insert(v[1]);
        }

        return cnt;
    }
};

// [[1,4],[2,8],[3,6]]