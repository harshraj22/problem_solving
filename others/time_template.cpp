#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     /*reading data*/
    time__("dfs"){
          /* dfs code */
    }
     /*some code*/
    time__("solve"){
       solve();
    }
}