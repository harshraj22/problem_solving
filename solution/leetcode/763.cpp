// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), _count = 0, first = 0, last = 0;
        vector<int> slices;
        // pair of (first_index, last_index)
        vector<pair<int, int>> range(26, {n, -1});

        for (int i = 0; i < n; i += 1) {
        	int index = s[i] - 'a';
        	range[index].first = min(range[index].first, i);
        	range[index].second = max(range[index].second, i);
        }

        // those chars which didn't occur, set their index out of range
        for (auto &pi: range) {
        	if (pi.first > pi.second)
        		pi = {n, n};
        }

        // sort the array (prepare for sweep line)
        sort(range.begin(), range.end());
        range.push_back({n, n});

        for (auto pi: range) {
        	if (pi.first > last) {
        		slices.push_back(last-first+1);
        		first = pi.first;
        	}
        	last = max(last, pi.second);
        }

        return slices;
    }
};

// "ababcbacadefegdehijhklij"
