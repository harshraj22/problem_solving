//https://w...content-available-to-author-only...j.com/problems/NAKANJ/

#include<bits/stdc++.h>
using namespace std;
int arr[9][9];
struct node{
int x;
int y;
int stp;
};

int main(){
ios_base::sync_with_stdio(false);
int test;
cin>>test;
while(test--){
    int i,j,k,n,m,l=1,r;
    char ch1,ch2;
memset(arr,0,sizeof(arr));
struct node ini,fi,var;
cin>>ch1>>ch2;
i=ch1-'a'+1;
j=ch2-'0';
//cout<<i<<" "<<j<<"\n";
ini.y=i;
ini.x=j;
ini.stp=0;
cin>>ch1>>ch2;
i=ch1-'a'+1;
j=ch2-'0';
//cout<<i<<" "<<j<<"\n";
fi.y=i;
fi.x=j;
fi.stp=0;
queue<node> q;
q.push(ini);
 arr[ini.x][ini.y]=1;
while(q.size()){
    ini=q.front();
    q.pop();
//    cout<<" bfs on "<<ini.x<<" "<<ini.y<<"\n";
    if(ini.x==fi.x && ini.y==fi.y){
        fi.stp=ini.stp+1;
        break;
    }
    i=ini.x;
    j=ini.y;
    if( i+2>0 && i+2<9 && j+1>0 && j+1<9 && !arr[i+2][j+1]){
        var.x=ini.x+2;
        var.y=ini.y+1;
        var.stp=ini.stp+1;
        arr[i+2][j+1]=1;
        q.push(var);
    }
    if( i+2>0 && i+2<9 && j-1>0 && j-1<9 && !arr[i+2][j-1]){
        var.x=ini.x+2;
        var.y=ini.y-1;
        var.stp=ini.stp+1;
        arr[i+2][j-1]=1;
        q.push(var);
    }
    if( i-2>0 && i-2<9 && j+1>0 && j+1<9 && !arr[i-2][j+1]){
        var.x=ini.x-2;
        var.y=ini.y+1;
        var.stp=ini.stp+1;
        arr[i-2][j+1]=1;
        q.push(var);
    }
    if(i-2>0 && i-2<9 && j-1>0 && j-1<9 && !arr[i-2][j-1]){
        var.x=ini.x-2;
        var.y=ini.y-1;
        var.stp=ini.stp+1;
        arr[i-2][j-1]=1;
        q.push(var);
    }
    if( i+1>0 && i+1<9 && j+2>0 && j+2<9 && !arr[i+1][j+2]){
        var.x=ini.x+1;
        var.y=ini.y+2;
        var.stp=ini.stp+1;
        arr[i+1][j+2]=1;
        q.push(var);
    }
    if( i+1>0 && i+1<9 && j-2>0 && j-2<9 && !arr[i+1][j-2]){
        var.x=ini.x+1;
        var.y=ini.y-2;
        var.stp=ini.stp+1;
        arr[i+1][j-2]=1;
        q.push(var);
    }
    if( i-1>0 && i-1<9 && j+2>0 && j+2<9 && !arr[i-1][j+2]){
        var.x=ini.x-1;
        var.y=ini.y+2;
        var.stp=ini.stp+1;
        arr[i-1][j+2]=1;
        q.push(var);
    }
    if( i-1>0 && i-1<9 && j-2>0 && j-2<9 && !arr[i-1][j-2]){
        var.x=ini.x-1;
        var.y=ini.y-2;
        var.stp=ini.stp+1;
        arr[i-1][j-2]=1;
        q.push(var);
    }
}

   cout<<fi.stp-1<<"\n";
}

return 0;
}

