# https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution:
    def get(self, segment, time):
        required = [time[index] for index in segment]
        return sum(required) - max(required)
    
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        indexes = [[]]
        cur_col = colors[0]
        
        # cut the colors into segments having same color
        # choose the most costly color from each segment
        
        for index, color in enumerate(colors):
            if color != cur_col:
                cur_col = color
                indexes.append([])
                
            indexes[-1].append(index)
            
        return sum(self.get(segment, neededTime) for segment in indexes)
        
        
