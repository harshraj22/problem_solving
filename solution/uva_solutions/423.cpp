// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=364
// Bellman Ford Basic Implementation

#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
#define ll long long int

int numOfVertices;
vector<pi> graph[101];

vector<ll> Distance(101,INT_MAX);

void bellman_ford(){
    for(int i=1;i<=numOfVertices;i++){
        for(auto it:graph[i]){
            int neighbour = it.second, weight = it.first;
            Distance[neighbour] = min(Distance[i] + weight, Distance[neighbour]);
        }
    }

}

int main(){

    cin >> numOfVertices;

    for(int i=2;i<=numOfVertices;i++){
        for(int j=1;j<i;j++){
            string s;
            cin >> s;
            if(s == "x")
                continue;
            int weight = stoi(s);
            graph[i].push_back(make_pair(weight,j));
            graph[j].push_back(make_pair(weight,i));

        }
    }
    Distance[1] = 0;

    for(int i=1;i<numOfVertices;i++)
        bellman_ford();

    cout << *max_element(Distance.begin()+2,Distance.begin()+1+numOfVertices) << "\n";

    return 0;
}