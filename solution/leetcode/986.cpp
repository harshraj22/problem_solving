// https://leetcode.com/problems/interval-list-intersections/
// basic sweep line

class Solution {
public:
    #define pi pair<int, int>
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ans;
        vector<pi> intervals;
        for (auto it:A) {
            pi var = {it[0], it[1]};
            intervals.push_back(var);
        }
        for (auto it:B) {
            pi var = {it[0], it[1]};
            intervals.push_back(var);
        }
        
        sort(intervals.begin(), intervals.end());
        int first = -1, last = -1;
        
        for (auto it: intervals) {
            if (last < it.first) {
                first = it.first;
                last = it.second;
                continue;
            }
            
            vector<int> v = {it.first, min(it.second, last)};
            ans.push_back(v);
            
            first = it.first;
            last = max(last, it.second);
        }
        
        return ans;
    }
};


/*
Two pointer based solution
class Solution {
    bool intersect(vector<int> a, vector<int> b) {
        if (a[0] > b[1] || a[1] < b[0])
            return false;
        return true;
    }

    vector<int> common(vector<int> a, vector<int> b) {
        return { max(a[0], b[0]), min(a[1], b[1]) };
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int i = 0, n = secondList.size();
        if (n == 0) return ans;
        
        for (auto first: firstList) {
            while (i < n && !intersect(first, secondList[i]) && first > secondList[i])
                i += 1;
            if (i < n && !intersect(first, secondList[i]))
                continue;
            while (i < n && intersect(first, secondList[i])) {
                ans.push_back(common(first, secondList[i])); 
                i += 1;
            }
            
            i -= 1;
        }

        return ans;
    }
};
*/