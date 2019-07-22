// https://discuss.codechef.com/t/cdrn04-time-complexity/32105
// MO's algorithm for offline queries
// refrence : geeksforgeeks and Gaurav Sen videos on YouTube
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=1e5+3;
int n,m,q,stu[N],par[N],a[N];
struct query{
    int l,r,id;
};

int block,ans[N];
query arr[N];

int find_par(int x){
    if(x==par[x])return x;
    return par[x]=find_par(par[x]);
}

void merge(int x,int y){
    x=find_par(x);
    y=find_par(y);
    if(x==y)return;
    par[x]=y;   stu[y]+=stu[x];
}

bool comp(query x,query y){
    if(x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

void queryResults(){
    int MAX=1e6;
    int currL = 0, currR = 0; 
    int curr_Diff_elements = 0; 
    int freq[MAX] = { 0 };
    for (int i = 1; i <= q; i++) { 
        int L = arr[i].l, R = arr[i].r;  
        while (currL < L) { 
            freq[a[currL]]--; 
            if (freq[a[currL]] == 0)  
                curr_Diff_elements--; 
              
            currL++; 
        }  
        while (currL > L) { 
            freq[a[currL - 1]]++; 
            if (freq[a[currL - 1]] == 1)  
                curr_Diff_elements++; 
              
            currL--; 
        } 
        while (currR <= R) { 
            freq[a[currR]]++; 
            if (freq[a[currR]] == 1)  
                curr_Diff_elements++; 
              
            currR++; 
        } 

        while (currR > R + 1) { 
            freq[a[currR - 1]]--; 
            if (freq[a[currR - 1]] == 0)  
                curr_Diff_elements--;              
            currR--; 
        } 
        ans[arr[i].id] = curr_Diff_elements; 
    } 
} 


void solve(){
    queryResults();
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
}


int main(){
    int x,y;
    cin>>n>>m>>q;   block=floor(sqrt(n));
    iota(par,par+n+1,0);
    fill(stu,stu+n+1,1);
    while(m--){
        cin>>x>>y;
        x=find_par(x);  y=find_par(y);
        if(x!=y && stu[x]%2==stu[y]%2)
            merge(x,y);
    }
    for(int i=0;i<N;i++)a[i]=find_par(i);

    for(int i=1;i<=q;i++){
        cin>>x>>y;
        arr[i].l=x,arr[i].r=y,arr[i].id=i;
    }
    sort(arr+1,arr+1+q,comp);
    solve();

    return 0;
}