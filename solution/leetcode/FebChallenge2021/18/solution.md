Problem:
   - [Day18](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3644/)

Tried:
   - Simple Math

``` cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size(), _cnt = 0, last = -1, ans = 0;
        if (n < 2) return 0;
		vector<int> diffs, lens;

		for (int i = 1; i < n; i += 1) 
			diffs.push_back(A[i] - A[i-1]);

		last = diffs[0] + 1;
		for (auto diff: diffs) {
			if (diff != last && _cnt) {
				lens.push_back(_cnt);
				_cnt = 1;
				last = diff;
			}
			else if (diff == last)
				_cnt += 1;
            else {
                _cnt += 1;
                last = diff;
            }
		}

		lens.push_back(_cnt);

		for (auto len: lens) {
		    len += 1;
            ans += len > 2 ? (len-1)*(len-2)/2 : 0;
        }

		return ans;
    }
};
```