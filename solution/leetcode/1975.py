# https://leetcode.com/problems/maximum-matrix-sum/

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        _sum = sum(sum(map(abs, row)) for row in matrix)
        negatives = 0
        for row in matrix:
            for val in row:
                if val < 0:
                    negatives = (negatives + 1) % 2
        
        # if num of -ve nums is odd, then subtract else not
        if negatives:
            offset = min(min(map(abs, row)) for row in matrix)
        else:
            offset = 0
        print(negatives, offset, _sum)
        return _sum - 2*offset
