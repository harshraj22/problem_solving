// https://leetcode.com/problems/container-with-most-water/
// Solution using Sorting
// Time: O(nlogn)  Space: O(n)

class Solution {
    int largest(vector<int> heights) {
        int n = heights.size(), ans = 0;
        vector<pair<int, int>> index(n);

        // this is useful in effectively finding the least index
        // where height >= height being currently iterated
        // Alternatively a segment tree can be used
        for (int i = 0; i < n; i += 1) 
            index[i] = {heights[i], i};
        sort(index.begin(), index.end());
        for (int i = n-2; i >= 0; i -= 1)
            index[i].second = min(index[i].second, index[i+1].second);

        for (int i = 0; i < n; i += 1) {
            // find the least index, where height is >= height[i]
            auto it = lower_bound(index.begin(), index.end(), make_pair(heights[i], -1));
            if (it->second == i)
                it += 1;
            if (it == index.end())
                continue;
            // try the area bounded by 'found-index' and 'i'
            int h = it->first, j = it->second;
            int area = (min(heights[i], h)*(i-j));
            ans = max(ans, area);
        }

        return ans;
    }

public:
    int maxArea(vector<int>& height) {
        // for the area bounded by the expected answer, if 
        // left boundary is samller than the right, it would 
        // be found in this step
        int ans = largest(height);

        // if left boundary is larger than the right, it would 
        // be found in this step
        reverse(height.begin(), height.end());
        return max(ans, largest(height));    
    }
};