#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=1e3+7;

ll ar[N][N],org[N][N],n,m,si,sj;

void dfs(int i,int j,int dist){
    if(i < 1 || i >n || j < 1 || j > m)
        return;
    else if(org[i][j])
        return;
    if(ar[i][j] <= dist && ar[i][j] >=0)
        return;
    ar[i][j] = dist;
    
    dfs(i+1,j,dist+1);
    dfs(i-1,j,dist+1);
    dfs(i,j+1,dist+1);
    dfs(i,j-1,dist+1);
}

void bfs(int i,int j,int dist){
    #define pi pair<int,int>
    #define mp make_pair
    #define pii pair<pi,int>
    queue<pii> q;
    q.push(mp(mp(i,j),dist));
    while(q.empty()==false){
        pii var = q.front();
        q.pop();
        int fi = var.first.first;
        int se = var.first.second;
        int di = var.second;
        if(fi <= 0 || fi > n || se <= 0 || se > m)
            continue;
        else if(ar[fi][se] >= 0)
            continue;
        else if(org[fi][se])
            continue;
        ar[fi][se] = di;
        q.push(mp(mp(fi+1,se),di+1));
        q.push(mp(mp(fi-1,se),di+1));
        q.push(mp(mp(fi,se+1),di+1));
        q.push(mp(mp(fi,se-1),di+1));
    }
}

void precompute(){
    // dfs(si,sj,0); gives TLE
    bfs(si,sj,0);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q,i;
    char var;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> var;
            ar[i][j] = -1;
            org[i][j] = (var == '*');
            // org = 1 if it is occupied
        }
    }
    cin >> si >> sj;
    precompute();
    while(q--){
        int di,dj;
        cin >> di >> dj;
        cout << ar[di][dj] << '\n';
    }

    return 0;
}