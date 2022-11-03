# https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

from collections import defaultdict

class Trie:
    def __init__(self, counts: int = 0) -> None:
        self.counts = counts
        self.edges = defaultdict(Trie)

    def insert(self, ch):
        node = self.get(ch)
        node.counts += 1
        return node

    def get(self, ch):
        return self.edges[ch]


class Solution:
    def __init__(self) -> None:
        self.trie = Trie()

    def sumPrefixScores(self, words: List[str]) -> List[int]:
        answers = [0 for _ in words]

        for index, word in enumerate(words):
            node = self.trie
            for ch in word:
                node = node.insert(ch)

        for index, word in enumerate(words):
            node = self.trie
            for ch in word:
                node = node.get(ch)
                answers[index] += node.counts

        return answers
        
