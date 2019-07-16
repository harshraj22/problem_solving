/*
	Policy based set of pairs(to be used as multiset)
	which supports element indexing at each node of segment tree.
	editorial : https://web.iiit.ac.in/~lalit.kundu/editorials.pdf 
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define mp make_pair
const int N=5e5+5;

typedef tree<pair<int, int>,null_type,
less<pair<int, int>>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int ar[N],n,nodes=0;
ordered_set seg[4*N];

void build(int nod,int l,int r){
    if(l==r){
        seg[nod].insert(mp(ar[l],++nodes));
        return;
    }
    int mid=l+(r-l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid+1,r);
    for(auto it:seg[nod*2])
        seg[nod].insert(it);
    for(auto it:seg[nod*2+1])
        seg[nod].insert(it);
}

int update(int nod,int l,int r,int u,int val){//u = a
    if(l==r){
        seg[nod].erase(seg[nod].lower_bound(mp(ar[u],0)));
        seg[nod].insert(mp(val,++nodes));
        int temp=ar[u];
        ar[u]=val;
        return temp;
    }
    int mid=l+(r-l)/2,temp;
    if(mid >= u)
        temp=update(nod*2,l,mid,u,val);
    else temp=update(nod*2+1,mid+1,r,u,val);

    seg[nod].erase(seg[nod].lower_bound(mp(temp,0)));
    seg[nod].insert(mp(val,++nodes));  
    return temp;
}

int query(int nod,int l,int r,int ql,int qr,int val){
    if(ql > r || qr < l)
        return 0;
    else if(ql<=l && qr>=r)
        return (int)seg[nod].size()-seg[nod].order_of_key(mp(val,-1));
    int mid=l+(r-l)/2;
    return query(nod*2,l,mid,ql,qr,val)+
            query(nod*2+1,mid+1,r,ql,qr,val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n; int q,a,b,c;
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>c;
        if(c==0){
            cin>>a>>b>>c;
            cout<<query(1,1,n,a,b,c)<<"\n";
        }
        else {
            cin>>a>>b;
            update(1,1,n,a,b);
        }
    }

    return 0;
}
