// https://leetcode.com/problems/validate-stack-sequences/
// Time: O(N), Space: O(N), Two Pointers

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int l = 0, r = 0;
        while (l < pushed.size()) {
        	while (!stk.empty() && r < popped.size() && stk.top() == popped[r]) {
        		r += 1;	stk.pop();
        	}

        	stk.push(pushed[l]);
        	l += 1;
        }

        while (r < popped.size() && stk.empty() == false && stk.top() == popped[r]) {
        	stk.pop();	r += 1;
        }

        return stk.empty();
    }
};