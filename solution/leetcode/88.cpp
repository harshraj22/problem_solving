// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m += n;
        // move all empty slots to the beginning
        for (int i = m-1; i >= n; i -= 1)
            swap(nums1[i], nums1[i-n]);
        // two pointers: the first pointing to first non zero element of num1
        //              second to the first non zero element of num2
        int first = n, second = 0;
        for (int i = 0; i < m; i += 1) {
            if (first < m && second < n) {
                if (nums1[first] < nums2[second]) {
                    nums1[i] = nums1[first];
                    first += 1;
                }   else {
                    nums1[i] = nums2[second];
                    second += 1;
                }
            }   else if (first < m) {   // if all elements of num2 have been included
                nums1[i] = nums1[first];
                first += 1;
            }   else {  // if all elements of num1 have been included
                nums1[i] = nums2[second];
                second += 1;
            }
        }
    }
};