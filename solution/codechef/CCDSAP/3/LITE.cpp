// Basic Lazy Propagation Segment Tree

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 1e5+3;
vector<int> seg(4*N+4,0),lazy(4*N+4,0);
int n,m;

int query(int node,int sl,int sr,int ql,int qr){
    if(ql > sr || qr < sl)
        return 0;
    else if(ql <= sl && qr >= sr){
        // the node contains answer
        if(lazy[node]%2==0)
            return  seg[node];
        else    
            return sr-sl+1-seg[node];
    }
    int mid = sl + (sr-sl)/2;
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
    seg[node] = query(node*2,sl,mid,sl,mid) + query(node*2+1,mid+1,sr,mid+1,sr);
    return query(node*2,sl,mid,ql,qr) + query(node*2+1,mid+1,sr,ql,qr);
}

int update(int node,int sl,int sr,int ul,int ur){
    if(ul > sr || ur < sl)
        return 0;
    if(ul<=sl && ur>=sr){
        lazy[node] += 1;
        
        if(lazy[node]%2==0)
            return seg[node];
        else return sr-sl+1-seg[node];
    }
    int mid = sl + (sr-sl)/2;
    lazy[node*2] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;

    update(node*2,sl,mid,ul,ur);  update(node*2+1,mid+1,sr,ul,ur);
    return seg[node] = query(node*2,sl,mid,sl,mid) + query(node*2+1,mid+1,sr,mid+1,sr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int type,l,r;
        cin >> type >> l >> r;
        if(type==1){
            cout << query(1,1,n,l,r) << '\n';
        }
        else{
            update(1,1,n,l,r);
        }
    }

    return 0;
}