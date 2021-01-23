Problem:
   - [Day23](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3614/)

Tried:
   - Iteration over each diagonal, and sorting

``` python
class Solution:
  def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
    if not mat:
      return mat
    n, m = len(mat), len(mat[0])
    # for each col head
    for _y in range(m):
      # collect the diagonal
      x, y, nums = 0, _y, []
      while y < m and x < n:
        nums.append(mat[x][y])
        x, y = x+1, y+1

      nums.sort()
      # replace the diagonal
      x, y, i = 0, _y, 0
      while y < m and x < n:
        mat[x][y] = nums[i]
        x, y, i = x+1, y+1, i+1


    # for each row head
    for _x in range(n):
      # collect the diagonal
      x, y, nums = _x, 0, []
      while y < m and x < n:
        nums.append(mat[x][y])
        x, y = x+1, y+1

      nums.sort()
      # replace the diagonal
      x, y, i = _x, 0, 0
      while y < m and x < n:
        mat[x][y] = nums[i]
        x, y, i = x+1, y+1, i+1

    return mat

```