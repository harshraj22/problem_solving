# https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        from collections import defaultdict
        groups, elements = [], defaultdict(list)
        
        for index, value in enumerate(groupSizes):
            elements[value].append(index)
            
            if len(elements[value]) == value:
                groups.append(elements[value])
                elements[value] = []
            
        return groups
        
        