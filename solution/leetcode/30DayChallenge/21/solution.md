Problem:
   - [Day21](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/)

Tried:
   - An awesome interactive problem
   - Used simple `Binary Search`

``` c++
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // for each row, find the pos of first 1, using binary search
        // update the answer
        
        auto dim = binaryMatrix.dimensions();
        int n = dim[0], m = dim[1], ans = m + 1;
        
        if (n == 0) return -1;
        
        // for each row
        for (int i = 0; i < n; i += 1) {
            // high denotes the first col, which has 1 in given row
            int low = 0, high = m - 1;
            // standard binary search
            while(low < high) {
                int mid = (low + high)/2;
                if (binaryMatrix.get(i, mid) == 1)
                    high = mid;
                else 
                    low = mid + 1;
            }
            // if the row didn't had any 1,
            if (binaryMatrix.get(i, low) == 1)
                ans = min(ans, low);
        }
        
        return (ans > m) ? -1 : ans;        
    }
};
```