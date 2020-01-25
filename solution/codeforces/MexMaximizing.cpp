// https://codeforces.com/contest/1294/problem/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
const int N=1e6+3;
vector<int> a(N,0),seg(4*N+8,0);
ll q,x;

void build(int node,int l,int r){
    if(l==r){
        seg[node] = l;
        return ;
    }

    ll mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node] = min(seg[node*2], seg[node*2+1]);
}

void update(int node=1,int l=0,int r=N,int index=0,int val=1){
    // update 1 at index=0 in 'a'
    // cout << "updating range " << l << " " << r << " \n";
    if(l==r){
        a[index] = val;
        seg[node] = N+5;
        return;
    }

    ll mid = (l+r)/2;
    if(index <= mid){
        update(node*2,l,mid,index,val);
    }
    else {
        update(node*2+1,mid+1,r,index,val);
    }
    seg[node] = min(seg[node*2],seg[node*2+1]);
}

ll query(int node=1,int l=0,int r=N,int ql=0,int qr=N){
    if(r<ql || qr<l)
        return N+3;
    else if(ql <= l && qr >= r){
        return seg[node];
    }

    ll mid=(l+r)/2;
    return min(query(node*2,l,mid,ql,qr), query(node*2+1,mid+1,r,ql,qr));
}

void solve(){
    cin >> q >> x;
    // vector<set<ll> > v(x);
vector<deque<int> > v(x);
    
    for(int i=0;i<=N;i++){
        // v[i%x].insert(i);
        v[i%x].push_back(i);
    }

    while(q--){
        ll var; cin >> var;
        ll varpar = var%x,Min;

        // what if v[varpar] is empty() ?
        if(v[varpar].size()==0){
            cout << query() << "\n";
            continue;
        }

        Min = *v[varpar].begin();
        // v[varpar].erase(Min);
        v[varpar].pop_front();
        update(1,0,N,Min,1);
        cout << query() << "\n";
    }
}

int main(){
    build(1,0,N);
    int test=1;
    // cin >> test;
    while(test--)
        solve();

    return 0;
}