#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

vector<int> ini,fin;
vector<vector<int> > dp;
int n;

int get(int i, int j){
    // base case, i.e. i<0 || j<0
    if(i<0 || j<0)
        return max(i+1,j+1);

    // if already calculated
    if(dp[i][j] != -1)
        return dp[i][j];
    
    // if both characters are same
    else if(ini[i] == fin[j])
        return dp[i][j] = get(i-1,j-1);

    // 
    else return dp[i][j] = (1+min(get(i-1,j),get(i,j-1)));
    
}

int solve(vector<string> s){
    int counter=1; n=s.size();
    unordered_map<string,int> mp;

    // ini represents initial configuration of input set of strings
    // fin represents final expected configuration of set of strings
    ini.resize(n);   fin.resize(n);
    for(int i=0;i<n;i++){
        // map all characters to integers so that comparision is fast enough
        if(mp[s[i]] == 0)
            mp[s[i]] = counter++ ;
        ini[i] = mp[s[i]];
    }

    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        fin[i] = mp[s[i]];
    }

    dp.resize(n+2);
    for(auto &it:dp)
        it.resize(n+2,-1);

    return get(n-1,n-1)/2;
}

class Books{
    public:
        int sortMoves(vector<string> S){
            return solve(S);
        }
};

// int main(){
//     Books obj;
//     vector<string> s = 	{"Algorithms", "Purely Functional Data Structures",
// "Intro to C", "Automata and Computability"};
//     cout << obj.sortMoves(s) << '\n';
//     for(auto it:ini)
//         cout << it << ' ';
//         cout << endl;
//     for(auto it:fin)
//         cout << it << ' ';
//         cout << endl;

//     cout << "the dp matrix is " << endl;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++)    
//             cout << dp[i][j] << ' ';
//         cout << '\n';
//     }

//     return 0;
// }