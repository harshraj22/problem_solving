// https://leetcode.com/problems/reducing-dishes/
// solved again on Apr28, 2021

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0, n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
    
        for (int start = 0; start < n; start += 1) {
            int sum = 0;
            for (int i = start; i < n; i += 1) {
                sum += satisfaction[i] * (i-start+1);
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};