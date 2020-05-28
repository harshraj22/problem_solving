// https://leetcode.com/problems/zigzag-conversion/
// Simulation using 2d-array

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // base case
		int n = s.size(), numCols = n + 1, offsetIndex = 0;
		vector<vector<char>> v(numRows, vector<char> (numCols, '#'));
		vector<pair<int, int>> offset = {{1, 0}, {-1, 1}};  // to change the direction
		string ans;

        // to check if given cell is valid
		auto isValid = [&](int i, int j)->bool{
			if (i < 0 || j < 0) return false;
			else if (j >= numCols || i >= numRows) return false;
			return true;
		};

		pair<int, int> start = {0, 0};

        // fill the matrix
		for (auto ch: s) {
			int x = start.first, y = start.second;
			int a = offset[offsetIndex].first, b = offset[offsetIndex].second;
			v[x][y] = ch;
            // if goes out of board, change direction
			if (!isValid(x+a, y+b)) 
				offsetIndex = 1 - offsetIndex;
			
			a = offset[offsetIndex].first, b = offset[offsetIndex].second;
			start = {x+a, y+b};
		}
        
        // calculate the answer string
		for (int i = 0; i < numRows; i += 1) {
			for (auto ch: v[i]) 
				if (ch != '#') ans += ch;
		}
		
		return ans;
    }
};