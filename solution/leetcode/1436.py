# https://leetcode.com/problems/destination-city/

# List unpacking ^_^
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        outdegree = {edge[0]:1 for edge in paths}
        for *others, node in paths:
            if node not in outdegree:
                return node

'''
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> outdegree;
        for (auto edge: paths) 
            outdegree[edge[0]] += 1;
        
        for (auto it: paths) {
            if (outdegree[it[1]] == 0)
                return it[1];
        }
        
        return "";
    }
};
'''

'''
/**
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function(paths) {
    let city = new Set(paths.map(path => path[0]));

    for (const [ ,dest] of paths) {
        if (!city.has(dest))
            return dest;
    }
};
'''
