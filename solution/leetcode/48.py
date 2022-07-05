# https://leetcode.com/problems/rotate-image/

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        new_matrix = [list(row)[::-1] for row in zip(*matrix)]
        matrix[:] = new_matrix
