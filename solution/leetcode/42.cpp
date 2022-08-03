// https://leetcode.com/problems/trapping-rain-water/
// solved again on April 30, 2021

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        vector<int> pref(n), suff(n);

        // pref[i]: nearest maxima (index < i)
        for (int i = 1; i < n; i += 1) 
            pref[i] = max(pref[i-1], height[i-1]);

        // suff[i]: nearest maxima (index > i)
        for (int i = n-2; i >= 0; i -= 1)
            suff[i] = max(suff[i+1], height[i+1]);

        for (int i = 1; i+1 < n; i += 1) {
            int h = min(pref[i], suff[i]);
            water += max(0, h-height[i]);
        }

        return water;
    }
};


/*
class Solution:
    def trap(self, height: List[int]) -> int:
        left = [0 for _ in height]
        right = [0 for _ in height]
        ans = 0
        
        for i, h in enumerate(height[1:], 1):
            left[i] = max(left[i-1], height[i-1])
            
        n = len(height)
        for i in range(n-2, -1, -1):
            right[i] = max(right[i+1], height[i+1])
        
        for i, h in enumerate(height[1:-1], 1):
            best = min(left[i], right[i]) - h
            ans += max(0, best)
            
        return ans
*/