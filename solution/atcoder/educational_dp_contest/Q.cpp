// array implementation of segment-tree ^_^ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll N = 2e5 + 5;
ll height[N],beauty[N],n,sol[N],num=2;

struct node{
    ll left=-1,right=-1,data=0;
    node(){
        left = -1;
        right = -1;
        data = 0;
    }
}seg[4*N];

ll query(int index,int l,int r,int ql,int qr){
    if(index<=0 || l>qr || r<ql)
        return 0;
    else if(ql<=l && qr>=r){

        return seg[index].data;
    }
    ll mid = (l+r)/2;
    return max(query(seg[index].left,l,mid,ql,qr),query(seg[index].right,mid+1,r,ql,qr));
}

void update(int index,int l,int r,int qp,ll qd){
    if(l==r){
        seg[index].data=max(qd,seg[index].data);
        return;
    }
    ll mid = (l+r)/2;
    if(qp<=mid){
        if(seg[index].left == -1)
            seg[index].left = num++;
        update(seg[index].left,l,mid,qp,qd);
        seg[index].data = max(seg[index].data,seg[seg[index].left].data);
    }
    else{
        if(seg[index].right == -1)
            seg[index].right = num++;
        update(seg[index].right,mid+1,r,qp,qd);
        seg[index].data = max(seg[index].data,seg[seg[index].right].data);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n; 
    for(int i=1;i<=n;i++)
        cin>>height[i];
    for(int i=1;i<=n;i++)
        cin>>beauty[i];
    for(int i=1;i<=n;i++){
        sol[i]=beauty[i]+query(1,1,n,0,height[i]-1);
        update(1,1,n,height[i],sol[i]);
    }
    cout<<query(1,1,n,1,n)<<"\n";   
    return 0;
}
/*
    Please Use array implementation of segment tree instead of pointer implementation.
    The difference between time is huge and can be observed in two solutions here :
    1. AC  https://atcoder.jp/contests/dp/submissions/7101148
    2. TLE  https://atcoder.jp/contests/dp/submissions/7091715

    The use of 'new' keyword is most probably the culprit behind making the second solution too costly.

*/