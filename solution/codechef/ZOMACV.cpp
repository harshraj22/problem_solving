#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long int 

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

const int N=1e5+3;
int ini[N+3],segment[4*N+2],lazy_update[4*N+2],n;

void solution();
int build(int ind,int l,int r);
int update(int ind,int l,int r,int ul,int ur);
int add(int ind,int l,int r);
void solution();

int main(){
  IOS;
int test;  cin>>test;
while(test--){
    solution();
}
    return 0;
}

int build(int ind,int l,int r){
    if(l==r){
        segment[ind]=ini[l];
        return 0;
    }
    ll mid=((l+r)/2);
    build(ind*2,l,mid);
    build(ind*2+1,mid+1,r);
    segment[ind]=(segment[ind*2]+segment[ind*2+1]);
    return 0;
}

int  update(int ind,int l,int r,int ul,int ur){
    if(ul>r || ur<l)
        return 0;

    if( l!=r && lazy_update[ind]!=0){
        lazy_update[ind*2]=lazy_update[ind*2]+lazy_update[ind];
        lazy_update[ind*2+1]+=lazy_update[ind];
    }
    else if(l==r)
        ini[l]=ini[l]+lazy_update[ind];
    lazy_update[ind]=0;

    if( ur>=r && ul<=l){
        lazy_update[ind]+=1;
        return 0;
    }
    ll mid=((l+r)/2);
    update(ind*2,l,mid,ul,ur);
    update(ind*2+1,mid+1,r,ul,ur);
    return 0;
}

int add(int ind,int l,int r){
    if(r==l){
        ini[l]=ini[l]+lazy_update[ind];
        lazy_update[ind]=0;
        return 0;
    }
    lazy_update[ind*2]=lazy_update[ind*2]+lazy_update[ind];
    lazy_update[ind*2+1]=lazy_update[ind*2+1]+lazy_update[ind];
    lazy_update[ind]=0;
    int mid=l+(r-l)/2;
    add(ind*2,l,mid);
    add(ind*2+1,mid+1,r);
    return 0;
}

void initialise(){
    memset(lazy_update,0,sizeof(lazy_update));
    memset(segment,0,sizeof(segment));
    memset(ini,0,sizeof(ini));
}

void solution(){
    initialise();
    ll i,j,k;
    cin>>n; vector<ll> vec(n+1);
    for(i=1;i<=n;i+=1)cin>>vec[i];
    build(1,1,n);
  // ------------
    for(i=1;i<=n;i+=1)
        update(1,1,n,i-vec[i],i+vec[i]);
    add(1,1,n);


    vector<ll> arr(n),ar(ini+1,ini+1+n);
    for(i=0;i<n;i+=1)cin>>arr[i];
    sort(arr.begin(), arr.end());
    sort(ar.begin(), ar.end());

    if(ar!=arr)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
