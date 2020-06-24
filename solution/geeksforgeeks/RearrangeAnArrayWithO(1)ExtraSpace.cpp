// https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space/0
    
// Idea is to store 2 numbers at one index

// Function to rarrange the elements in O(1) extra space
// arr: input array
// n: size of array
void arrange(long long arr[], int n) {
    int mod = 1 + *max_element(arr, arr+n);
    
    // store second element for each position
    for (int i = 0; i < n; i += 1) {
        int original = arr[i] % mod;
        int extra = arr[original] % mod;
        arr[i] = original + mod*extra;
    }
    
    // remove original element for each position
    for (int i = 0; i < n; i += 1)
        arr[i] /= mod;
}
