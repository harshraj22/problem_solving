// https://leetcode.com/problems/longest-consecutive-sequence/
// This is quite popular technique to find next present element
// Use of DSU

class Solution {
    unordered_map<int, int> par, val;
    int findPar(int num) {
        if (par.find(num) == par.end())
            return num;
        return par[num] = findPar(par[num]);
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for (auto num: nums) {
            val[num] = 1;
            if (val.find(num-1) != val.end())
                val[num] += val[num-1];
            int p = findPar(num+1);  par[num] = p;
            int low = num - val[num];
            val[p-1] = p - low - 1;
            ans = max(ans, val[p-1]);
        }

        return ans;
    }
};


/* [100,4,200,1,3,2]
[1,2,3,4,5]
[1,5,2,4,3] */