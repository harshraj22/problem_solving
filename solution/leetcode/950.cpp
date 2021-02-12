// https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    	int n = deck.size(), j = 0;
    	sort(deck.begin(), deck.end());
    	vector<int> ans(n);
    	deque<int> dq;
    	
    	for (int i = 0; i < n; i += 1)
    		dq.push_back(i);
        
        while (!dq.empty()) {
        	int i = dq.front();
        	dq.pop_front();
        	ans[i] = deck[j];
        	j += 1;

        	if (!dq.empty()) {
        		dq.push_back(dq.front());
        		dq.pop_front();
        	}
        }

        return ans;
    }
};