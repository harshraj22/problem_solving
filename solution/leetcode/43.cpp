// https://leetcode.com/problems/multiply-strings/
// another standard problem of arithemetic using strings/ linked-lists

class Solution {
    string add (string s1, string s2) {
        // adds two string and returns the result as a string
        if (s1 == "0") return s2;
        else if (s2 == "0") return s1;
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        int first = 0, carry = 0;
        string ans;
        
        while(first < s1.size() && first < s2.size()) {
            int sum = (s1[first] - '0') + (s2[first] - '0') + carry;
            ans += to_string(sum%10);
            carry = sum/10;     first += 1;
        }
        
        if (first >= s1.size())
            swap(s1, s2);
        
        while (first < s1.size()) {
            int sum = (s1[first] - '0') + carry;
            ans += to_string(sum%10);
            carry = sum/10;     first += 1;
        }
        
        if (carry > 0) {
            ans += to_string(carry);
            carry = 0;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;        
    }
    
    string mult (string s, char ch) {
        // multiplies a char with a string and returns the result as a string
        
        string ans;  int carry = 0;
        reverse(s.begin(), s.end());
        
        for (auto c: s) {
            int u = (c - '0'), v = (ch - '0');
            ans += to_string((u*v+carry)%10);
            carry = (u*v+carry)/10;
        }
        
        if (carry > 0) {
            ans += to_string(carry);
            carry = 0;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string ans, padding;
        reverse(num2.begin(), num2.end());
        
        for (auto ch: num2) {
            string var = mult(num1, ch) + padding;
            ans = add(ans, var);
            padding += '0';
        }
        
        return ans;
    }
};