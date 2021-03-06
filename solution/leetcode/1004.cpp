// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int zero = 0, ans = 0, left = 0, right = 0, n = A.size();   
        
        while (right < n) {
            while (right < n && zero <= k) {
                zero += (A[right] == 0);
                right += 1;
            }
            
            ans = max(ans, right-left-1);
            
            while (zero > k) {
                zero -= (A[left] == 0);
                left += 1;
            }
        }
        
        if (zero <= k)
            ans = max(ans, right-left);
        
        return ans;        
    }
};
