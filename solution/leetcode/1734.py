# https://leetcode.com/problems/decode-xored-permutation/

class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        total_zor = 0
        n = len(encoded) + 1
        for i in range(n+1):
            total_zor ^= i
        
        nums = [0 for _ in range(n)]
        for perm in encoded[1::2]:
            nums[0] = nums[0] ^ perm
        nums[0] ^= total_zor
        for index, _ in enumerate(nums[1:], 1):
            nums[index] = nums[index-1] ^ encoded[index-1]
        
        return nums
