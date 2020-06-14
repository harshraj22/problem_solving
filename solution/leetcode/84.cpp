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