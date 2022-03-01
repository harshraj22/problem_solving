# https://leetcode.com/problems/car-fleet/

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        tups = list(zip(position, speed))
        tups.sort()
        time_req = [(target-_position)/ _speed for _position, _speed in tups]
        _max_val = -2
        _st = set()
        
        for req in reversed(time_req):
            if req <= _max_val:
                continue
            _st.add(req)
            _max_val = req
            
        return len(_st)
