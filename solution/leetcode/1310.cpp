// https://leetcode.com/problems/xor-queries-of-a-subarray/
// Time: O(N) Space: O(N)
// Prefix Sum type solution

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n, arr[0]), res;

        for (int i = 1; i < n; i += 1)
        	pref[i] = pref[i-1] ^ arr[i];

        for (auto q: queries) {
        	int sum = pref[q[1]] ^ pref[q[0]] ^ arr[q[0]];
        	res.push_back(sum);
        }

        return res;
    }
};