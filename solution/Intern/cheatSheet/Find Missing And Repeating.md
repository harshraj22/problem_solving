Question [Link](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0)

Time: O(n)
Space: O(1)

Basic Idea Used: `Store two numbers at one index`, the first is the original number, the second is the freq of number
represented by the index. Find the number whose freq is 0 and whose freq is 2.

```c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

// repr: original_num + mod*freq_of_index
// to extract freq: num/mod
// to extract original_num: num % mod
// Choose mod carefully (obiously it should be > max(all(nums)))
void find_missing_repeating(vector<int> &nums, int &missing, int &repeating) {
    int n = nums.size(), mod = nums.size()+1;
    for (int i = 0; i < n; i += 1) {
        int num = nums[i] % mod;
        int freq = nums[num-1]/ mod;
        nums[num-1] = nums[num-1]%mod + mod*(freq + 1);
    }

    for (int i = 0; i < n; i += 1) {
        int num = i + 1;
        int freq = nums[i]/mod;
        if (freq == 0)
            missing = num;
        else if (freq == 2)
            repeating = num;
    }
}

void solve() {
    int n, missing=0, repeating=0;  cin >> n;
    vector<int> nums(n);
    for (auto &num: nums)
        cin >> num;
    find_missing_repeating(nums, missing, repeating);
    cout << repeating << ' ' << missing << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int test = 1;
    cin >> test;
    while(test--)
        solve();
    
    return 0;
}

```