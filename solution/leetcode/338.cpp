// https://leetcode.com/problems/counting-bits/

class Solution {
    int count_bits(int num) {
        int ans = 0;
        for (int i = 0; i <= 32; i += 1) {
            ans += (num & (1LL << i)) ? 1: 0;
        }
        return ans;
    }
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        for (int i = 0; i <= num; i += 1)
            v[i] = count_bits(i);
        return v;
    }
};