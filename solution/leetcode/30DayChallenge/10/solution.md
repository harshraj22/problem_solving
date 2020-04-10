Problem:
   - [Day10](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/)

Tried:
   - Another Awesome `Stack` Based Solution

``` c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> normal, minimum;
    
    MinStack() {
        
    }
    
    void push(int x) {
        normal.push(x);
        if (!minimum.empty())
            x = min(x, minimum.top());
        minimum.push(x);
    }
    
    void pop() {
        normal.pop();
        minimum.pop();
    }
    
    int top() {
        return normal.top();
    }
    
    int getMin() {
        return minimum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```