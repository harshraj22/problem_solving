# https://leetcode.com/problems/coloring-a-border/

import sys
sys.setrecursionlimit(10000000)

class Solution:
	from copy import deepcopy

	def neighbours(self, x, y):
		return [(x+1, y), (x-1, y), (x, y-1), (x, y+1)]


	def dfs(self, masked_grid, org_grid, visited, x, y, org_col, col):
		if masked_grid[x][y] != org_col:
			return
		elif visited[x][y]:
			return
		visited[x][y] = True

		for xx, yy in self.neighbours(x, y):
			if org_grid[xx][yy] != org_col:
				masked_grid[x][y] = col

		for xx, yy in self.neighbours(x, y):
			self.dfs(masked_grid, org_grid, visited, xx, yy, org_col, col)


	def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
		n, m = len(grid), len(grid[0])
		# create masked grid
		masked_grid = [[-1]*(m+2)] + [[-1] + row.copy() + [-1] for row in grid] + [[-1]*(m+2)]

		org_col = grid[r0][c0]
		visited = [[False for _ in row] for row in masked_grid]
		# dfs from (r0+1, c0+1)
		self.dfs(masked_grid, deepcopy(masked_grid), visited, r0+1, c0+1, org_col, color)

		# trim masked grid and return
		return [x[1:-1] for x in masked_grid[1:-1]]

