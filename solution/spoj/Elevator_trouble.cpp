#include<bits/stdc++.h>
using namespace std;

int main(){
int f,s,u,d,j,k,i,n,m=0,g,l=0,a=1;
cin>>f>>s>>g>>u>>d;
/*
if(s!=g && u==d){
    cout<<"use the stairs\n";
    return 0;
}
else if(d>s && u>f-s){
    cout<<"use the stairs\n";
    return 0;
}
*/
vector<int> arr(f+1,0);
queue<pair<int,int > > que;
pair<int,int> pi;
que.push(make_pair(s,0));
arr[s]=1;
while(que.size()){
    pi=que.front();
    que.pop();
    if(pi.first==g){
        break;
    }
    
    if(pi.first+u<=f && !arr[pi.first+u]){
        que.push(make_pair(pi.first+u,pi.second+1));
        arr[pi.first+u]=1;
    }
    if(pi.first-d>0 && !arr[pi.first-d]){
        que.push(make_pair(pi.first-d,pi.second+1));
        arr[pi.first-d]=1;
        }
}
if(pi.first!=g)
        cout<<"use the stairs\n";
else cout<<pi.second<<"\n";



return 0;
}
