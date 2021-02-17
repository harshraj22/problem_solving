Problem:
   - [Day17](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/)

Tried:
   - Good sorting based solution

``` cpp
#define pi pair<int, int>
#define all(x) x.begin(), x.end()

class Solution {
	int lb(vector<pi> &v, int h) {
		if (h > v.back().first)
			return -1;
		int left = 0, right = (int)v.size() - 1;
		while (left < right) {
			int mid = (left + right)/2;
			if (v[mid].first >= h)
				right = mid;
			else 
				left = mid + 1;
		}

		return left;
	}

public:
    int maxArea(vector<int>& height) {
    	int n = height.size();
        vector<pi> items(n), left, right;

        for (int i = 0; i < n; i += 1)
        	items[i] = {height[i], i};

        left = items;
        right = items;

        sort(all(left), [](pi a, pi b) {
        	if (a.first != b.first)
        		return a.first < b.first;
        	return a.second < b.second;
        });

        // for a given height, we need to find the leftmost index i
        // such that height[i] >= given height, so such sorting
        // and maintaining prefix sum kind of history
        for (int i = n-2; i >= 0; i -= 1)
        	left[i].second = min(left[i].second, left[i+1].second);

        sort(all(right),  [](pi a, pi b) {
        	if (a.first != b.first)
        		return a.first < b.first;
        	return -a.second < -b.second;
        });

        // for a given height, find the rightmost index i, such that
        // height[i] >= given height
        for (int i = n-2; i >= 0; i -= 1)
        	right[i].second = max(right[i].second, right[i+1].second);

        int ans = 0, max_height = *max_element(all(height));

        // h denotes the height of water level
        for (int h = 0; h <= max_height; h += 1) {
        	// find left most, right most index with height >= h
        	int index_l = lb(left, h), index_r = lb(right, h);

        	// if such index exist, try to update answer
        	if (index_l != -1 && index_r != -1)
        		ans = max(ans, h * (right[index_r].second - left[index_l].second));
        }

        return ans;
    }
};        
```