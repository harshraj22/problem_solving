Question [Link](https://leetcode.com/problems/set-matrix-zeroes/)

Time: O(m * n)
Space: O(1)

Basic Idea Used: Use first element in row and col as flag to indicate if there is a 0 in corresponding row/ col. Handle the case of first row/ col seperately

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        bool zero_in_first_row = !(find(matrix[0].begin(), matrix[0].end(), 0) == matrix[0].end());
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 1; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i += 1) {
            for (int j = m-1; j >= 0; j -= 1) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (zero_in_first_row)
            fill(matrix[0].begin(), matrix[0].end(), 0);
    }
};
```

