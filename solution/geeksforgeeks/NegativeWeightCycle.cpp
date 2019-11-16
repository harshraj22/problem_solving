// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>

#define inf 0x3f3f3f3f

int vertices, edges;
vector<pi> graph[101];
vector<int> dist(101,inf);

bool bellman_ford(){
    bool ans = false;
    for(int i=1;i<=vertices;i++){
        for(auto it:graph[i]){
            int neighbour = it.second, weight = it.first;
            if(dist[neighbour] > dist[i] + weight){
                ans = true;
                dist[neighbour] = dist[i] + weight;
            }
        }
    }
    return ans;
}

void init(){
    fill(dist.begin(),dist.end(),inf);
    for(int i=0;i<101;i++)
        graph[i].resize(0);
}

void solve(){
    cin >> vertices >> edges;
    for(int i=0;i<edges;i++){
        int from,to,weight;
        cin >> from >> to >> weight;
        graph[from+1].push_back(make_pair(weight, to+1));
    }
    for(int i=1;i<vertices;i++)
        bellman_ford();
    cout << bellman_ford() << '\n';
}

int main(int argc, char**argv){
    int test;
    cin >> test;
    while(test--){
        init();
        solve();
    }

    return 0;
}