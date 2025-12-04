// https://leetcode.com/problems/largest-rectangle-in-histogram/
// Time: (nlogn) using divide and conquer

class Solution {
    int area;
    void recur(vector<int> &heights, int left, int right) {
        if (left == right) {
            area = max(area, heights[left]);
            return;
        }

        int mid = (left + right)/2, mn = INT_MAX;
        recur(heights, left, mid);
        recur(heights, mid+1, right);
        int i = mid, j = mid+1;

        while (left <= i && right >= j) {
            if (heights[i] > heights[j]) {
                mn = min(mn, heights[i]);
                i -= 1;
            }
            else {
                mn = min(mn, heights[j]);
                j += 1;
            }
            area = max(area, mn*(j-i-1));
        }

        while (left <= i) {
            mn = min(mn, heights[i]);
            i -= 1;
            area = max(area, mn*(j-i-1));
        }

        while (right >= j) {
            mn = min(mn, heights[j]);
            j += 1;
            area = max(area, mn*(j-i-1));
        }

        return area;
    }

public:
    Solution() {
        area = 0;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        recur(heights, 0, n-1);
        return area;        
    }
};


/*
// Alternate solution in O(nlogn) Time, O(n) space using property of set that it is always sorted.


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        set<pair<int, int>> intervals;
        intervals.insert(make_pair(0, heights.size()));
        
        // find indexes corresponding to each height
        map<int, vector<int>> indexes;
        
        for (int i = 0; i < heights.size(); i += 1)
            indexes[heights[i]].push_back(i);
        
        int ans = 0;
        // iterate over heights in increasing order
        // 1. find interval of indexes in which its index lies
        // 1.5 remove it from the set of indexes
        // 2. try to update answer (height * width = area for current rectangle)
        // 3. insert new intervals (current index breaks the existing interval into two)
        for(auto _pair: indexes) {
            int height = _pair.first;
            for(auto index: _pair.second) {
                // 1.
                auto it = intervals.lower_bound(make_pair(index, -1));
                if (it == intervals.end() or it->first > index)
                    it = prev(it);
                auto interval = *it;
                
                // 1.5
                intervals.erase(it);
                
                // 2.
                ans = max(ans, height * (interval.second - interval.first));
                
                // 3. 
                if (index > interval.first)
                    intervals.insert(make_pair(interval.first, index));
                if (index+1 < interval.second)
                    intervals.insert(make_pair(index+1, interval.second));
                
            }
        }
        
        return ans;
    }
};


Alternate solution using O(N) time and O(N) space using monotonic stack

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ansFromLeft = self.getAnswer(heights)
        ansFromRight = self.getAnswer(heights[::-1])[::-1]

        return max(x + y - z for x, y, z in zip(ansFromLeft, ansFromRight, heights))

    def getAnswer(self, heights):
        """Returns List ans, such that ans[i] is the length of largest
        rectangle formed by heights[:i+1] where heights[i] is included"""

        stack = []
        ans = [0 for _ in heights]

        for index, height in enumerate(heights):
            # get the closest index of element smaller than 'height'
            closestIndex = None
            while stack and heights[stack[-1]] >= height:
                stack.pop()
            
            if not stack:
                closestIndex = -1
            else:
                closestIndex = stack[-1]

            ans[index] = height * (index - closestIndex)

            # update the stack
            while stack and heights[stack[-1]] >= height:
                stack.pop()
            
            stack.append(index)

        return ans
*/
