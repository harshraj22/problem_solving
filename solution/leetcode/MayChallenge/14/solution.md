Problem: 
   - [Day 14](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/)

Tried: 
   - Used `Trie` data structure

```python
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.transition = {}
        self.endOfWord = False
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if not word:
            self.endOfWord = True
        else:
            self.transition[word[0]] = self.transition.get(word[0], Trie())
            self.transition[word[0]].insert(word[1:])
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if not word:
            return self.endOfWord
        elif word[0] not in self.transition:
            return False
        else:
            return self.transition[word[0]].search(word[1:])
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if not prefix:
            return True
        elif prefix[0] not in self.transition:
            return False
        return self.transition[prefix[0]].startsWith(prefix[1:])
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
```