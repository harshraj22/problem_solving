# https://leetcode.com/problems/match-substring-after-replacement/

from collections import defaultdict
from unittest import defaultTestLoader


class Solution:
    def get_mappings(self, target, sub):
        mapping = defaultdict(set)
        for ct, cs in zip(target, sub):
            if ct == cs:
                continue
            mapping[cs].add(ct)
        return mapping

    def check(self, dst, src):
        for char, st in src.items():
            if st.intersection(dst[char]) == st:
                continue
            return False
        return True

    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        n, m = len(s), len(sub)
        mapping = defaultdict(set)
        for (src, dst) in mappings:
            mapping[src].add(dst)

        for index in range(n):
            if index + m > n:
                break
            target = s[index: index+m]
            reqired = self.get_mappings(target, sub)
            # if required in mappings: return True
            if self.check(mapping, reqired):
                return True

        return False