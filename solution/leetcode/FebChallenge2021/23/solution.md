Problem:
   - [Day23](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3650/)

Tried:
   - Traverse over matrix using sorted property of row and columns

``` cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        auto inside = [&](int x, int y) {
        	if (min(x, y) < 0) return false;
        	else if (x >= n || y >= m) return false;
        	return true;
        };

        int i = n-1, j = 0;

        while (inside(i, j)) {
        	if (matrix[i][j] == target)
        		return true;
        	else if (matrix[i][j] > target)
        		i -= 1;
        	else
        		j += 1;
        }

        return false;
    }
};
```