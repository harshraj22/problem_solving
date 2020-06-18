Problem: 
   - [Day 18](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3364/)

Tried: 
   - Good `Binary Search`


```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
   		int n = citations.size();
   		if (n == 0) return 0;
   		// ============================ for O(n) complexity =================================
   		// for (int i = citations.back(); i >= 0; i -= 1) {
   		// 	int larger = citations.end() - upper_bound(citations.begin(), citations.end(), i);
   		// 	if (larger >= i)
   		// 		return i;
   		// }
   		// =================== for O(logn) complexity, binary search ========================
   		int high = citations.back(), low = 0;
   		while (low < high) {
   			int mid = (high + low + 1)/2;
   			int larger = citations.end() - lower_bound(citations.begin(), citations.end(), mid);
   			if (larger >= mid)
   				low = mid;
   			else 
   				high = mid-1;
   		}

   		return low;    
    }
};
```