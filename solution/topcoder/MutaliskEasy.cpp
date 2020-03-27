// https://community.topcoder.com/stat?c=problem_solution&cr=40181316&rd=16461&pm=13782

#include<bits/stdc++.h>
using namespace std; 

#define ll long long int
#define pi pair<int,int> 

#define mx 62
int dp[mx][mx][mx];
vector<int> input;
vector<int> var={9,3,1};

int recur(int a,int b,int c){
    a = max(a,0);
    b = max(b,0);
    c = max(c,0);

    if(dp[a][b][c] != -1)
        return dp[a][b][c];
    int mn=INT_MAX;
    for(auto i:var){
        for(auto j:var){
            for(auto k:var){
                if(i!=j && j!=k && k!=i){
                    mn=min(mn,1+recur(a-i,b-j,c-k));
                }
            }
        }
    }
    return dp[a][b][c]=mn;
}

class MutaliskEasy{
    public:

    MutaliskEasy(){
        for(int i=0;i<mx;i++){
            for(int j=0;j<mx;j++){
                for(int k=0;k<mx;k++)
                    dp[i][j][k] = -1;
            }
        }
        dp[0][0][0] = 0;
    }

    int minimalAttacks(vector<int> &v){
        while(v.size() < 3)
            v.push_back(0);
        input=v;
        int ans=INT_MAX;
        for(auto i:var){
            for(auto j:var){
                for(auto k:var){
                    if(i!=j && j!=k && i!=k){
                        int variable = 1+recur(v[0]-i,v[1]-j,v[2]-k);
                        ans = min(ans,variable);
                    }
                }
            }
        }
        return ans;
    }
};

// int main(){
//     MutaliskEasy obj;
//     vector<int> v={55,60,53};
//     cout << obj.minimalAttacks(v) << "\n";

//     return 0;
// }