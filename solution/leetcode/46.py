# https://leetcode.com/problems/permutations/

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        
        def recur(cur, more):
            if not more:
                permutations.append(cur)
            
            for index, val in enumerate(more):
                recur(cur+[val], more[:index]+more[index+1:])
                
        recur([], nums)
        return permutations