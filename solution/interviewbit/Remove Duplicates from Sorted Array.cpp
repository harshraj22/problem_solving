// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
// Two pointers to swap elements
// Time: O(n), Space: O(1)

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	// left: position where next distinct element should be placed
	// right: position where next distinct element is present
    int n = A.size(), left = 0, right = 0;
    while (right < n) {
        A[left] = A[right];
        left += 1;  right += 1;
        while (right < n && A[right] == A[right-1])
            right += 1;
    }
    
    return left;
}
