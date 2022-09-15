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

/*
Solved Again using DSU in python
I'm still worthy Lol


class Solution:
    def __init__(self):
        self.parent = []
        self.length = []
        self.position = dict()
        
    def find_parent(self, index):
        if self.parent[index] == index:
            return index
        self.parent[index] = self.find_parent(self.parent[index])
        return self.parent[index]
    
    def merge(self, u, v):
        if u not in self.position or v not in self.position:
            return
            
        u_index = self.find_parent(self.position[u])
        v_index = self.find_parent(self.position[v])
        
        # v is smaller
        self.length[v_index] += self.length[u_index]
        self.parent[u_index] = v_index

        
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums: return 0
        nums = list(set(nums))
        n = len(nums)
        self.parent = list(range(n))
        self.length = [1 for _ in self.parent]
        
        for index, num in enumerate(nums):
            self.position[num] = index
            
        for num in nums:
            self.merge(num, num-1)
        
        return max(self.length)
        


*/
