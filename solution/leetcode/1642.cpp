// https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int index = 1; // index to go
        multiset<int> dists;

        for ( ; index < heights.size(); index += 1) {
            int req = max(0, heights[index] - heights[index-1]);
            if (req == 0) continue;
            
            if (ladders > 0) {
                ladders -= 1;
                dists.insert(req);
            }
            else {
                // the largest height diff should be replaced
                // by the ladder
                if (dists.empty() == false && req > *dists.begin()) {
                    int var = *dists.begin();
                    dists.erase(dists.begin());
                    dists.insert(req);
                    req = var;
                }

                // if we can pay by bricks
                if (bricks >= req) {
                    bricks -= req;
                }
                else {
                    return index - 1;
                }
            }
        }

        return index - 1;
    }
};