#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

const int N=1e4+3;
set<int> g[N];
int n;
vector<int> v;

bool tropo();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
int i,j,k,m;
cin>>n>>m;
for(i=0;i<m;i++){
    cin>>j>>k;
    g[j].insert(k);
}
if(tropo())
    for(auto it:v)
        cout<<it<<" ";
else cout<<"Sandro fails.";
cout<<"\n";
    return 0;
}

bool tropo(){
    priority_queue<int,vector<int>,greater<int> > pq;
    vector<int> indeg(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto it:g[i])
            indeg[it]++;
    }
    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
            pq.push(i);
        
    while(pq.empty()==0){
        auto j=pq.top();    pq.pop();
        v.eb(j);
        for(auto it:g[j]){
            indeg[it]--;
            if(indeg[it]==0)
                pq.push(it);
        }
    }
    if(v.size()!=n) return false;
    else return true;
}