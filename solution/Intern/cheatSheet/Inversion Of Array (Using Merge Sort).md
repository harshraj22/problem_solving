Question [Link](https://practice.geeksforgeeks.org/problems/inversion-of-array/0)

Time: O(n * logn * logn) can be reduced to O(n * logn) using two pointers one in left sub-half and other in right as both are sorted <br>
Space: O(logn) -Recursion

Basic Idea used: Use divide and conquer to count inversions in left and right sub-halves. After counting, sort the sub-half. Use binary search to count the inversions.

```c++
#include<bits/stdc++.h>
using namespace std;

void countInversions(vector<long long int> &nums, long long int &inversions, long long int left, long long int right) {
    if (left == right) return;
    long long int mid = (left+right)/2;
    countInversions(nums, inversions, left, mid);
    countInversions(nums, inversions, mid+1, right);

    // for each element in left subpart
    for (long long int i = left; i <= mid; i += 1) {
        // count how many elements were less than it in right subpart
        inversions += (lower_bound(nums.begin()+mid+1, nums.begin()+right+1, nums[i]) - nums.begin() - (mid+1));
    }

    // sort(nums.begin()+left, nums.begin()+right+1);
    vector<long long int> var;
    merge(nums.begin()+left, nums.begin()+mid+1, nums.begin()+mid+1, nums.begin()+right+1, back_inserter(var));
    copy(var.begin(), var.end(), nums.begin()+left);
}

void solve() {
    long long int n, inversions = 0;  cin >> n;
    vector<long long int> nums(n);
    for (auto &num: nums) 
        cin >> num;
    countInversions(nums, inversions, 0, n-1);
    cout << inversions << endl;
}


int main() {
    int tests;  cin >> tests;
    while (tests--)
        solve();

    return 0;
}


```