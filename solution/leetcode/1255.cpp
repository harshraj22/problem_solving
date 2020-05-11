// https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// P.S. No need to use map<char, deque<int>>, map<char, int> would do as well as each char has
// same score each time it occurs in 'letters' array

class Solution {
    vector<string> words;
    vector<char> letters;
    vector<int> score;
    map<char, deque<int>> freq;

	bool isSet(int bit, int num) {
		return num & (1LL << bit);
	}
    
    int encode(int num) {
        int profit = 0; map<char, deque<int>> cur_freq = freq;
        for (int i = 0; i < 32; i += 1) {
            if (!isSet(i, num))
				continue;
			string s = words[i];	
			for (auto ch: s) {
				if (cur_freq[ch].size() == 0)
					return -1e6;
				else {
					profit += cur_freq[ch].front();
					cur_freq[ch].pop_front();
				}
			}
        }
		return profit;
    }
    
public:
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& s) {
        words = w; letters = l; score = s;
        for (int i = 0; i < letters.size(); i += 1) 
			freq[letters[i]].push_back(score[letters[i]-'a']);

		for (auto &it: freq)
			sort(it.second.begin(), it.second.end(), greater<int>());
        
        int n = words.size(), ans = 0;
        for  (int i = 0; i < (1LL << n); i += 1) {
            ans = max(ans, encode(i));
        }
        
        return ans;
    }
};
