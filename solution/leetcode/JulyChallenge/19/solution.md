Problem: 
   - [Day 19](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/)

Tried: 
   - 


```c++
class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i, carry = 0;
        for (i = 0; i < min(a.size(), b.size()); i += 1) {
            int cur = carry + (a[i]-'0') + (b[i]-'0');
            sum += (cur % 2 + '0');
            carry = cur/2;
        }
        
        if (a.size() > b.size())
            swap(a, b);
        while (i < b.size()) {
            int cur = carry + (b[i]-'0');
            sum += (cur % 2 + '0');
            carry = cur/2;      
            i += 1;
        }
        
        if (carry)
            sum += '1';
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
```
