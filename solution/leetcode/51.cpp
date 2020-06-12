// https://leetcode.com/problems/n-queens/

class Solution {
    vector<vector<string>> ans;

    bool isValid(vector<vector<string>> &matrix, int row, int col) {
        // checks if matrix is valid, given that queen is placed at (row, col)
        int n = matrix.size();

        // to check if a point is inside the matrix
        auto inside = [&](int x, int y)->bool{
            if (x < 0 || y < 0) 
                return false;
            else if (x >= n || y >= n)
                return false;
            return true;
        };

        // check in vertical dir
        for (int i = 0; i < row; i += 1) {
            if (matrix[i][col] == "Q")
                return false;
        }

        // check diagonally 
        vector<pair<int, int>> dia = {{-1, -1}, {-1, 1}};
        for (auto offset: dia) {
            int x = row + offset.first, y = col + offset.second;
            while (inside(x, y)) {
                if (matrix[x][y] == "Q")
                    return false;
                x += offset.first;
                y += offset.second;
            }
        }

        return true;
    }

    bool setQueens(vector<vector<string>> &matrix, int row) {
        // set a queen in the given row
        if (row >= matrix.size()) {
            vector<string> v;
            for (auto row: matrix) 
                v.push_back(accumulate(row.begin(), row.end(), string(), [](string a, string b){ return a + b; }));
            ans.push_back(v);
            return true;
        }
        // for given row, try at each column position
        for (int col=0; col < matrix.size(); col += 1) {
            // if it doesn't kill any queen
            if (isValid(matrix, row, col)) {
                // add queen to the given position
                matrix[row][col] = "Q";
                // try to fill queen in next row
                setQueens(matrix, row+1);
                matrix[row][col] = ".";
            }
        }

        // if no-where the queen can be placed in the given row
        // probably we need to shift queen in previous rows
        return false;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> matrix(n, vector<string> (n, "."));
        for (int index = 0; index < n; index += 1) { 
            matrix[0][index] = "Q";
            setQueens(matrix, 1);
            matrix = vector<vector<string>> (n, vector<string> (n, "."));
        }

        return ans;
    }
};
