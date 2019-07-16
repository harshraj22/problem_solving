// coded with care ^_^
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e6+5;
#define eb emplace_back

int check_prime[N]={0},a[N],n,lval,rval,x,y;
vector<int> prime,av[N],seg[4*N];

void precompute(){
    for(int i=2;i<N;i++){
        if(check_prime[i]==0){
            prime.eb(i);
            for(int j=i;j<N;j+=i)
                check_prime[j]=1;
        }
    }
}

vector<int> factorise(int val){
    vector<int> ans;
    int limit=1+floor(sqrt(val));
    for(int i=2;i<=limit;i++){
        while(val%i==0){
            val/=i; ans.eb(i);
        }
    }
    if(val!=1)ans.eb(val);
    return ans;
}

void once(){
    for(int i=1;i<=n;i++)
        av[i]=factorise(a[i]);
}


void build(int node,int l,int r){
    if(l==r){
        seg[node]=av[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node].reserve(seg[node*2].size()+seg[node*2+1].size());
    merge(seg[node*2].begin(),seg[node*2].end(),
        seg[node*2+1].begin(), seg[node*2+1].end(),back_inserter(seg[node]));
}

int search(int node,int l,int r,int ql,int qr){
    if(qr<l || ql>r)return 0;
    // query range > segment range
    if(ql <= l && qr >= r){
        return upper_bound(seg[node].begin(),seg[node].end(),y)-
                    lower_bound(seg[node].begin(),seg[node].end(),x);
    }
    int mid=(l+r)/2;
    return search(node*2,l,mid,ql,qr)+search(node*2+1,mid+1,r,ql,qr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int i,q,k;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    precompute();
    once(); build(1,1,n);
    cin>>q;
    while(q--){
        cin>>lval>>rval>>x>>y;
        cout<<search(1,1,n,lval,rval)<<"\n";
    }
    return 0;
}
