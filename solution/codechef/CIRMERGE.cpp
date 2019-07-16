#pragma GCC optimize ("Ofast")

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=401;
ll inf=(1e17);
ll table[N][N],v[N],n,p[N];

ll fin(int index,int length);

ll mod(int k,int n){
    if(k<n)return k;
    else return k-n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
int test;   cin>>test;
while(test--){
    memset(table,-1,sizeof(table));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i>0)p[i]+=p[i-1];
    }
    // partial_sum(v,v+n,p);
    for(int col=0;col<n;col++){//length
        for(int row=0;row<n;row++){//index
            if(col==0){
                table[row][col]=0;
                continue;
            }
            ll var=inf,sum1=0,sum2=0;
            for(int mid=0;mid<col;mid++){
                sum1=p[mod(row+mid,n)];
                if(row > 0)sum1-=p[row-1];
                if(sum1 < 0)sum1+=p[n-1];

                sum2=p[mod(row+col,n)];
                if(mod(row+mid+1,n) > 0)sum2-=p[mod(row+mid+1,n)-1];
                if(sum2 < 0)sum2+=p[n-1];
                var=min(var,table[row][mid]+table[mod(row+mid+1,n)][col-mid-1]+sum1+sum2);
            }
            table[row][col]=var;
        }
    }
    ll var=inf;
    for(int i=0;i<n;i++)
        var=min(var,table[i][n-1]);
    cout<<var<<"\n";

}
    return 0;
}

/*
1
30
1 2 3 1 1 7 7 1 2 3 1 2 3 1 1 7 7 1 2 3 1 2 3 1 1 7 7 1 2 1
375

1
5
3 10 2 2 2
37
*/
