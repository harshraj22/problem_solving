# https://leetcode.com/problems/maximum-binary-string-after-change/

class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        if '0' not in binary or binary.count('0') == 1:
            return binary
        num_zeros = binary.count('0')
        index_of_first_zero = binary.index('0')
        ans = ['1' for _ in binary]
        ans[index_of_first_zero + num_zeros -1] = '0'
        return ''.join(ans)
        
        
