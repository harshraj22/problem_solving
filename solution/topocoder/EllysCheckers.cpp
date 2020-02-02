// https://community.topcoder.com/stat?c=problem_statement&pm=11791

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class EllysCheckers{
    public:
        string getWinner(string s){
            vector<string> ans = {"NO","YES"};
            const int N = ((1<<20) + 5);
            // dp[i] denotes, if current player gets group represented by i, can he/she win 
            vector<int> dp(N,-1);
            int n = 0;
            reverse(s.begin(),s.end());

            // find initial configuration of groups
            for(int i=0;i<s.size();i++){
                if(s[i] == 'o')
                    n = n|(1<<i);
            }
            dp[0] = dp[1] = 0;

            // iterate over each bit, each i represents a group
            for(int i=1;i<N;i++){
                if(dp[i] != -1)
                    continue;
                // assume that group represented by i, can't make player currently playing win
                dp[i] = 0;

                // remember we need to ignore rightmost bit
                for(int bit=1;bit<=20;bit++){
                    // if 'bit'th bit is set, player will move it right trying to win
                    if(i & (1<<bit)){
                        // ignore rightmost bit,(if it is set, unset it)
                        int j=i-i%2;

                        // jump 1 step right, but next bit should be unset (given condition)
                        if(bit>0 && (j&(1<<(bit-1)))==0){
                            // unset 'bit'th bit and set 'bit-1'th bit
                            dp[i] = max(dp[i], 1 - dp[(j&(~(1<<bit)))|(1<<(bit-1))]);
                        }
                        // try to jump 3 bits, remember bits jumped over must be unset
                        if(bit>3 && (j&(1<<(bit-1)))==0 && (j&(1<<(bit-2)))==0 && (j&(1<<(bit-3)))==1)
                            dp[i] = max(dp[i], 1 - dp[(j&(~(1<<bit)))|(1<<(bit-3))]);
                        // if jump is made to rightmost bit, no need to consider state of rightmost bit
                        else if(bit==3 && (j&(1<<(bit-1)))==0 && (j&(1<<(bit-2)))==0){
                            dp[i] = 1;
                        }
                    }
                }
            }
            return ans[dp[n]];
        }
};

// int main(){
//     EllysCheckers obj;
//     string ss;   cin >> ss;
//     cout << obj.getWinner(ss) << '\n';

//     return 0;
// }
