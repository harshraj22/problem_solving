// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

int searchPivot(vector<int> &nums, int left, int right) {
    // searches the index of maxima O(logn)
    if (left == right)
        return left;
    int mid = (left + right)/2;
    if (nums[mid+1] < nums[left])
        return searchPivot(nums, left, mid);
    return searchPivot(nums, mid+1, right);
}

void solve(){
    int n, target;  cin >> n;
    vector<int> nums(n);
    for (auto &num: nums)
        cin >> num;    
    cin >> target;

    int index = searchPivot(nums, 0, n-1);
    // seperate the array into 2 sorted array and do binary search
    if (target >= nums[0]) 
        cout << (binary_search(nums.begin(), nums.begin()+index+1, target) ? lower_bound(nums.begin(), nums.begin()+index+1, target) - nums.begin(): -1) << '\n';
    else 
        cout << (binary_search(nums.begin()+index+1, nums.end(), target) ? lower_bound(nums.begin()+index+1, nums.end(), target) - nums.begin(): -1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}