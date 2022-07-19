# https://leetcode.com/problems/longest-common-prefix/


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = []
        
        for chars in zip(*strs):
            if len(set(chars)) == 1:
                common.append(chars[0])
            else:
                break
                
        return ''.join(common)