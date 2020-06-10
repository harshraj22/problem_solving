Question [Link](https://leetcode.com/problems/pascals-triangle/)

Time: O(n * n)
Space: O(n * n)

Basic Idea Used: Simulation, use formula of calculating the triangle.

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0) return triangle;
        else triangle.push_back(vector<int>(1, 1)); numRows -= 1;
        while (numRows--) {
            int n = (int)triangle.size() -1;
            triangle.push_back(vector<int>(1, 1));
            for (int i = 0; i + 1 < triangle[n].size(); i += 1) 
                triangle.back().push_back(triangle[n][i] + triangle[n][i+1]);
            triangle.back().push_back(1);
        }
        
        return triangle;
    }
};
```