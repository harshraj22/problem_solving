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

/*

class Solution:
    from collections import defaultdict
    
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        from sortedcontainers import SortedList
        
        used = defaultdict(SortedList)
        # maintain a sorted ordered list of differences in heights
        # fill the smaller ones with brick, and larger ones with ladders
        
        # once a new difference of height arrives, try to fill it with
        # brick, it might require converting the larger difference (which is
        # currently filled with brick) to ladder
        for index, height in enumerate(heights[1:], 1):
            diff = height - heights[index-1] 
            if diff <= 0:
                continue
            elif diff <= bricks:
                used['bricks'].add(diff)
                bricks -= diff
                continue
            elif ladders == 0:
                return index - 1
            
            while bricks < diff:
                if ladders == 0:
                    return index-1
                
                if len(used['bricks']) == 0 or used['bricks'][-1] < diff:
                    used['ladders'].add(diff)
                    ladders -= 1
                    break
                
                brick = used['bricks'][-1]
                used['bricks'].pop()
                
                ladders -= 1
                used['ladders'].add(brick)
                bricks += brick
                
            if bricks >= diff:
                used['bricks'].add(diff)
                bricks -= diff
                
                
        return len(heights) - 1
            
                    

*/
