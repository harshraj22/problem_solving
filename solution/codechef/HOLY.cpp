// https://www.codechef.com/COZI2019/problems/HOLY
// Initially it might look like a O(n*k) or O(n2) solution, but looking closely at it shows that it is a O(n). The technique is called sliding window and is quite popular for solving such types of questions. Alternative solution can use Segment tree

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    ll ans = INT_MAX,l=0,r=0;
    for(auto &it:a)
        cin >> it;
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
        ans = min(ans,abs(sum-k));
        while(sum > k){
            sum -= a[l];
            l++;
        }
        ans = min(ans,abs(sum-k));
    }
    cout << ans << endl;
    return 0;
}