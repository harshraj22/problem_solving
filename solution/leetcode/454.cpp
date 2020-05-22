// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> first, second; int ans = 0;

        // generate sum from all distinct pair (i, j)
        for (int i = 0; i < A.size(); i += 1) {
            first.push_back(A[i] + B[i]);
            for (int j = 0; j < B.size(); j += 1) {
                if (i != j)
                    first.push_back(A[i] + B[j]);
            }
        }

        // generate sum from all distinct pair (i, j)
        for (int i = 0; i < C.size(); i += 1) {
            second.push_back(C[i] + D[i]);
            for (int j = 0; j < D.size(); j += 1) {
                if (i != j)
                    second.push_back(C[i] + D[j]);
            }
        }

        // sort for binary search to count freq in log(n)
        sort(second.begin(), second.end());
        for (auto num: first)
            ans += upper_bound(second.begin(), second.end(), -num) - lower_bound(second.begin(), second.end(), -num);

        return ans;
    }
};
