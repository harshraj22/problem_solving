// https://leetcode.com/problems/combination-sum/

class Solution {
    void backtrack(int index, int curSum, vector<int> curNums,
    		 int target, vector<int> &candidates, vector<vector<int>> & combs) {
        if (curSum > target)
            return;
        else if (curSum == target) {
            combs.push_back(curNums);
            return;
        }
        
        curNums.push_back(0);
        for (int i = index; i < candidates.size(); i += 1) {
            int num = candidates[i];
            curNums.back() = num;
            backtrack(i, curSum+num, curNums, target, candidates, combs);
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        backtrack(0, 0, vector<int>(), target, candidates, combs);
        return combs;
    }
};