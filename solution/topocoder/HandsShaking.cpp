#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N=51;
ll dp[N][N];

void init(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dp[i][j] = -1;
}

ll recur(int a, int b){
    // form the circle with people [a,b] and solve recursively
    if(a<=0 || b<=0)
        return 0;
    else if(a==b)
        return 0;
    else if(abs(a-b)<=1)
        return 1;
    else if(a > b)
        return 0;
    else if((b-a)%2==0)
        return 0;
    else if(dp[a][b] != -1){
        return dp[a][b];    
    }
    dp[a][b] = 0;

    for(int i=a+1;i<=b;i++){
        if((i-a+1)%2==1 || (b-i)%2==1)
            continue;
        dp[a][b] += recur(a+1,i-1) * recur(i+1,b);
    }
    return dp[a][b];
}

class HandsShaking{
    public:
    long long int countPerfect(int n){
        long long int ans=0;   init();
        for(int i=2;i<=n;i++){
            if(i%2==1 || (n-i)%2==1)
                continue;
            // divide the circle into 2, with diagonal as (1,i)
            ans += recur(2,i-1) * recur(i+1,n);
        }
        return ans;
    }
};

// int main(){
//     HandsShaking obj;
//     cout << obj.countPerfect(8) << '\n';

//     return 0;
// }