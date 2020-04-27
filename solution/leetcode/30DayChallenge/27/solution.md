Problem:
   - [Day27](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3312/)

Tried:
   - Used standard `Dynamic Programming` O(n2) space and O(n3) time
   - Could have reduced to O(n<sup>2</sup>logn) time by `binary search` instead of `linear search` to find the bottom-right corner of required square.

``` c++
class Solution {
    int n, m, ans = 0;
    vector<vector<int>> dp;
    
    bool isValid(int i, int j) {
        if (i < 0 || j < 0) return false;
        else if (i >= n || j >= m) return false;
        return true;
    }
    
    void precalculate(vector<vector<char>> & matrix) {
    	// precalcualate the prefix sum
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                dp[i][j] = (matrix[i][j] == '1');
                if (isValid(i-1, j))
                    dp[i][j] += dp[i-1][j];
                if (isValid(i, j-1))
                    dp[i][j] += dp[i][j-1];
                if (isValid(i-1, j-1))
                    dp[i][j] -= dp[i-1][j-1];
            }
        }
    }
    
    int query(int row, int col, vector<vector<char>> &matrix) {
        int i = row, j = col;
        if (matrix[i][j] == '0') return 0;

        while (isValid(i+1, j+1) && matrix[i+1][j+1] == '1') {
            int area = dp[i+1][j+1]; 
            
            if (isValid(row-1, j+1))
                area -= dp[row-1][j+1];
            if (isValid(i+1, col-1))
                area -= dp[i+1][col-1];
            if (isValid(row-1, col-1))
                area += dp[row-1][col-1];
            
            if (area != (i-row+2)*(j-col+2)) break;
            else {
                i += 1; j += 1;
            }
        }
        
        return (i-row+1)*(j-col+1);
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        n = matrix.size(), m = matrix[0].size();
        
        dp.resize(n, vector<int>(m));
        for (auto &row: dp) {
            for (auto &element: row)
                element = 0;
        }
        
        precalculate(matrix);
        
        // iterate over each pair (i, j) and update answer if
        // (i, j) were the starting top-left vertex of our 
        // required matrix.
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                ans = max(ans, query(i,j, matrix));
            }
        }
        
        return ans;
    }
};
```
