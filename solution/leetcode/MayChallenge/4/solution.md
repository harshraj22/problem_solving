Problem: 
   - [Day 4](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/)

Tried: 
   - Use of `bits` of number

```c++
    class Solution {
        int leftmostSetBit(int n) {
            return int(log2(n));
        }
        
        bool isSet(int bit, int num) {
            return num & (1 << bit);
        }
        
        int setBit(int bit, int num) {
            return num | (1 << bit);
        }
        
    public:
        int findComplement(int num) {
            int left = leftmostSetBit(num), ans = 0;
            for (int i = 0; i <= left; i += 1) {
                if (isSet(i, num) == false)
                    ans = setBit(i, ans);
            }
            
            return ans;
        }
    };
```

```python
class Solution:
    def findComplement(self, num: int) -> int:
        ans = bin(num)[1:].lstrip('0')
        ans = ''.join(['1' if ch == '0' else '0' for ch in ans])
        return int(ans, 2)
```