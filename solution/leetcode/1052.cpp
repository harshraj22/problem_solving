// https://leetcode.com/problems/grumpy-bookstore-owner/
// Solved again on 22 Feb 2021

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        int n = grumpy.size(), N = 20000;
        vector<int> custPrefSum(2*N, customers[0]), satPref(n+2), satSuff(2*N);
        
        for (int i = 1; i < custPrefSum.size(); i += 1) {
            custPrefSum[i] = custPrefSum[i-1];
            if (i < customers.size())
                custPrefSum[i] += customers[i];
        }

        for (int i = 0; i < n; i += 1) {
            if (grumpy[i] == 1)
                continue;
            satPref[i] += customers[i];
            satSuff[i] += customers[i];
        }

        for (int i = 1; i < satPref.size(); i += 1)
            satPref[i] += satPref[i-1];

        for (int i = N-2; i >= 0; i -= 1)
            satSuff[i] += satSuff[i+1];


        // for each time ti, assume [ti, ti+x) to be not grumpy
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            int _count = custPrefSum[i+x-1] - (i > 0 ? custPrefSum[i-1] : 0);
            int nxt = satSuff[i+x];
            int prv = (i > 0 ? satPref[i-1] : 0);

            cout << i << ' ' << _count << ' ' << prv << ' ' << nxt << '\n';
            ans = max(ans, _count + nxt + prv);
        }

        return ans;
    }
};  