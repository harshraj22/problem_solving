// https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
// BruteForce solutin, Time: O(N*M*M) space: O(1), 

// Time complexity can be improved using method similar to counting sort
// Iterate over all char, for each char, compare all strings based on that char
// i.e. for i in range(M): for j in range(N) cmp(A[j][i], A[j+1][i]) and so on

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int count = 0, size = A[0].size();
        
        auto get = [&](string &s1, string &s2)->int{
            for (int i = 0; i < s1.size(); i += 1) {
                if (s1[i] > s2[i])
                    return i;
            }
            return 0;
        };
        
        auto subtract = [&](int index)->void{
            for (int i = 0; i < A.size(); i += 1) 
                A[i][index] = '\0';
        };
        
        for (int i = 0; i + 1 < A.size(); i += 1) {
            if (A[i] > A[i+1]) {
                int index = get(A[i], A[i+1]);
                subtract(index);    count += 1;
                i = -1;
            }
        }
        
        return count;
    }
};