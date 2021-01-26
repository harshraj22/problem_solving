# https://leetcode.com/problems/partition-labels/

class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        index, sizes = dict(), []
        # print(len(S))
        
        for i, val in reversed(list(enumerate(S))):
            if val not in index:
                index[val] = i
            
        left, cur, right = 0, 0, 0
        while left < len(S):
            right = max(right, index[S[left]])
            cur += 1
            if left == right:
                sizes.append(cur)
                right, cur = right + 1, 0
            left += 1
        return sizes
            