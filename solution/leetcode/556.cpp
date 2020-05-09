// https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        n = s.size(); map<char, int> pos;
        for (int i = n-1; i > 0; i -= 1) {
			pos[s[i]] = i;
            if (s[i] > s[i-1]) {
				int index = pos.upper_bound(s[i-1])->second;
                swap(s[index], s[i-1]);
                sort(s.begin()+i, s.end());
                return (stol(s) >= INT_MAX) ? -1: stoi(s);
            }
        }
        return -1;
    }
};