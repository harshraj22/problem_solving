// https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> person(1002, 0);
        for (auto trip: trips) {
            int num = trip[0], start = trip[1], end = trip[2];
            person[start] += num;
            person[end] -= num;
        }
        
        for (int i = 0, cur = 0; i < person.size(); i += 1) {
            cur += person[i];
            if (cur > capacity)
                return false;
        }
        
        return true;
    }
};