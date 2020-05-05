// https://leetcode.com/problems/largest-number/submissions/
// Sorting based implementation problem
// Time: O(n*nlogn) as comparision of 2 string takes O(n)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        v.reserve(nums.size());
        for (auto num: nums) 
            v.push_back(to_string(num));
        
        auto cmp = [&](string s1, string s2)->bool{
            // returns if s1 < s2
            return s1 + s2 < s2 + s1;
        };
        
        sort(v.begin(), v.end(), cmp);
        reverse(v.begin(), v.end());

        string ans ;
        for (auto str: v)
            ans += str;
        int i = 0;  // for cases like '00' should be returned as '0'
        while(i+1 < ans.size() && ans[i] == '0' && ans[i+1] == '0')
            i += 1;
        
        return string(ans.begin()+i, ans.end());
    }
};

/* 
class Solution:
    from functools import cmp_to_key
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        
        def cmp(s1, s2):
            # return int(s2+s1) - int(s1+s2)
            if s1 == s2:
                return 0
            elif s1 + s2 > s2 + s1:
                return 1
            else:
                return -1
        
        nums = sorted(nums, key=cmp_to_key(cmp), reverse=True)
        ans = ''.join(nums)
        if ans.startswith('0'):
            ans = '0' + ans.lstrip('0')
        return ans
*/