Problem:
   - [Day9](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3598/)

Tried:
   - BFS over the generated words

``` python
class Solution:
	def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
		from collections import deque

		if beginWord == endWord:
			return 0+1

		alphabets = 'abcdefghijklmnopqrstuvwxyz'
		wordList = set(wordList)
		beginWord = list(beginWord)

		queue = deque([(beginWord, 0)])
		visited = set()

		while queue:
			word, length = queue.popleft()
			if ''.join(word) == endWord:
				return length+1
			visited.add(''.join(word))
			for index, _ in enumerate(word):
				for ch in alphabets:
					newWord = ''.join(word[:index] + [ch] + word[index+1:])
					if newWord not in visited and newWord in wordList:
						visited.add(newWord)
						queue.append([list(newWord), length+1])
		return 0
```