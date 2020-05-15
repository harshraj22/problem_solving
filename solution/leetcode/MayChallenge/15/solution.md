Problem: 
   - [Day 15](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/)

Tried: 
   - Used basic `prefix sum` and `kadane's Algo`
   - Time: O(n) space: O(n)

```c++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        long long int sum = INT_MIN, cur_sum = 0, n = A.size();
        vector<long long int> pref_sum(n, A[0]), left(n), right(n, INT_MIN);

        // max sum in given array
        for (auto num: A) {
            cur_sum += num;
            sum = max(sum, cur_sum);
            cur_sum = max(cur_sum, 0LL);
        }

        // left[i]: max prefix sum upto and including index i
        left[0] = max(A[0], 0);
        // first prefix
        for (int i = 1; i < n; i += 1) {
            pref_sum[i] = pref_sum[i-1] + A[i];
            left[i] = max(left[i-1], pref_sum[i]);
        }

        // right[i]: max suffix sum upto but excluding index i
        fill(pref_sum.begin(), pref_sum.end(), A.back());
        // now suffix
        for (int i = n-2; i >= 0; i -= 1) {
            pref_sum[i] = pref_sum[i+1] + A[i];
            right[i] = max(right[i+1], pref_sum[i+1]);
        }
        
        for (int i = 0; i < n; i += 1)
            sum = max(sum, left[i]+right[i]);
        

        return sum;
    }
};
```