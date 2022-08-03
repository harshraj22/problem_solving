// https://leetcode.com/problems/daily-temperatures/
// Another awesome problem using stack
// Time: O(n) - each element is pushed/poped only once from stack, Space: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size(); stack<pair<int, int>> stk;
		vector<int> ans(n, 0);
        // notice stack.first is always in increasing order
        // if any element comes that is greater than first element
        // all elements less than new element are popped
		stk.push({T.back(), n-1});

		for (int i = n-2; i >= 0; i -= 1) {
			while (!stk.empty() && T[i] >= stk.top().first)
				stk.pop();
			if (!stk.empty())
				ans[i] = stk.top().second - i;
			stk.push({T[i], i});
		}
        
		return ans;
    }
};

/*
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        indexes = [n-1]
        answer = [0 for _ in temperatures]
        
        for i in range(n-2, -1, -1):
            while indexes:
                last = indexes[-1]
                if temperatures[last] <= temperatures[i]:
                    indexes.pop()
                    continue
                else:
                    answer[i] = last - i
                    break
            indexes.append(i)
        return answer
*/