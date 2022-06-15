// https://leetcode.com/problems/longest-string-chain/

class Solution {
    unordered_map<string, int> mp;
    vector<string> input;

    int get(string s) {
        if (mp.find(s) != mp.end())
            return mp[s];
        else if (binary_search(input.begin(), input.end(), s) == 0)
            return INT_MIN;
        else if (s.size() == 1)
            return mp[s] = 1; 
        int ans = 1;   string str;
        for (int i = 0; i < s.size(); i += 1) {
            str = string(s.begin(), s.begin()+i) + string(s.begin()+i+1, s.end());
            ans = max(ans, 1 + get(str));
        }

        return mp[s] = ans;
    }

public:
    int longestStrChain(vector<string>& words) {
        input = words; int ans = 0;
        sort(input.begin(), input.end());
        for (auto word: words) 
            ans = max(ans, get(word));
        return ans;
    }
};


/*

class Solution:
    def is_pred(self, w1: str, w2: str):
        """Checks if w1 is a predecessor of w2."""
        if len(w1) + 1 != len(w2):
            return False
        for index, (ch1, ch2) in enumerate(zip(w1, w2)):
            if ch1 != ch2:
                return w1[index:] == w2[index+1:]
        
        # The last character differs
        return True
    
    def longestStrChain(self, words: List[str]) -> int:
        len_of_pred = [1 for _ in words]
        words.sort(key=lambda word: len(word))
        
        for i, word in enumerate(words):  # O(n^2)
            for j, prev_word in enumerate(words[:i]):
                if self.is_pred(prev_word, word):
                    len_of_pred[i] = max(len_of_pred[i], 1 + len_of_pred[j])
                    
        return max(len_of_pred)


*/
