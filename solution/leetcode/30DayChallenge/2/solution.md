Problem:
   - [Day2](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/)

Tried:
   - ```labmda``` functions in c++.

``` c++
// basic bruteforce
class Solution {
public:
    bool isHappy(int n) {
        auto sumOfSquares = [](int num, int ans=0)->int {
            while (num) {
                int last = num % 10;
                ans += (last * last);
                num /= 10;
            }
            
            return ans;
        };
        
        int num = n;    set<int> numbers;
        
        while (num != 1 && numbers.find(num) == numbers.end()) {
            numbers.insert(num);
            num = sumOfSquares(num);
        }
        
        if (num == 1)
            return true;
        return false;
    }
};
```

``` c++
// idea from discussion forum

class Solution {
public:
    bool isHappy(int n) {
        auto sumOfSquares = [](int num, int ans=0)->int {
            while (num) {
                int last = num % 10;
                ans += (last*last);
                num /= 10;
            }
            return ans;
        };
        
        int slow = n, fast = sumOfSquares(n);
        
        while (slow != fast) {
            if (slow == 1)
                return true;
            slow = sumOfSquares(slow);
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
        }

        if (slow == 1)
            return true;
        return false;
    }
};
```