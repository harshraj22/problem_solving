# https://leetcode.com/problems/reverse-words-in-a-string/

class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])

'''
class Solution {
    vector<string> split(string s) {
        vector<string> splitted;
        string str;
        for (auto ch: s) {
            if (isspace(ch) && str.size()) {
                splitted.push_back(str);
                str = "";
            }   else if (!isspace(ch)) {
                str += ch;
            }
        }
        
        if (str.size())
            splitted.push_back(str);
        
        return splitted;
    }
public:
    string reverseWords(string s) {
        vector<string> splitted = split(s);
        reverse(splitted.begin(), splitted.end());
        if (splitted.empty())
            return "";
        
        string ans = splitted[0];
        for (int i = 1; i < splitted.size(); i += 1) {
            ans += " ";
            ans += splitted[i];
        }
        
        return ans;
    }
};
'''