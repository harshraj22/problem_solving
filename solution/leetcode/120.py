# https://leetcode.com/problems/triangle/

class Solution:
	from math import inf

	def minimumTotal(self, triangle: List[List[int]]) -> int:
		# create a copy
		dp = [[inf for _ in row] for row in triangle]
		dp[0][0] = triangle[0][0]

		for i, row in enumerate(dp[:-1]):
			for j, cell in enumerate(row):
				try:
					dp[i+1][j] = max(dp[i+1][j], dp[i][j] + triangle[i+1][j])
					dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1])
				except IndexError:
					pass
		return min(dp[-1])	