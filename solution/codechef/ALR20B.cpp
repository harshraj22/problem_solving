// https://www.codechef.com/ALRA2020/problems/ALR20B

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9+7;
#define pi pair<ll,ll>
const int N = 1e6+1;

void solve(){
	string s;	cin >> s;
	int cur_y = 0, cur_x = 0;
	// start = 0,0

	// representing [-N,N] (0 mapped to N)
	vector<ll> pos(2*N+3,0),neg(2*N+3,0);

	for(int i=0;i<s.size();i++){
		if(s[i]=='L'){
			cur_x -= 1;
		}
		else if(s[i] == 'R'){
			cur_x += 1;
		}
		else if(s[i]=='U'){
			if(cur_y >= 0)
				pos[cur_x+N] += 1;
			else 
				neg[cur_x+N] -= 1;
			cur_y += 1;
		}
		else{
			// s[i] = D
			if(cur_y > 0)
				pos[cur_x+N] -= 1;
			else 
				neg[cur_x+N] += 1;
			cur_y -= 1;
		}
	}

	ll ans = 0, cur_sum = 0;

	for(int i=N;i>=-N;i--){
		int ind = N+i;
		cur_sum += pos[ind]; 

		// ans += len*width (area enclosed in col, above x-axis)
		ans += cur_sum*1;
	}

	cur_sum = 0;
	for(int i=N;i>=-N;i--){
		int ind = N+i;
		cur_sum -= neg[ind];

		// ans += len*width (area enclosed in col, below x-axis)
		ans += cur_sum;
	}

	cout << abs(ans) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test=1;
	cin >> test;
	while(test--)
		solve();

	return 0;
}