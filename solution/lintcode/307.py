# https://www.lintcode.com/problem/307/

class Solution:
    """
    @param A: a string A
    @param B: a string B
    @return: return the minimum number of operations to transform
    """
    from collections import Counter
    def transform(self, A, B):
        if sorted(A) != sorted(B):
            return -1
        # find len of subsequence of A[::-1] that is prefix of B[::-1]
        length = 0

        # convert to problem where char can be picked and placed at end
        A = ''.join(A[::-1])
        B = ''.join(B[::-1])

        # creating iterator so that each char can be consumed only once
        _b, _a = iter(B), iter(A)
        for char_b in _b:
            for char_a in _a:
                if char_a == char_b:
                    length += 1
                    break

        # ans is len(B) - found length
        return len(B) - length
