// https://cses.fi/problemset/task/1634
// Important point to note was to sort the coins (see Erritcho's Expectation values
// 		youtube video for more details)
// Recursive solution gives TLE, Iteration is faster than Recursion !

#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

const int N = 1e6;
const int inf = 1e7;

vector<vector<int>> dp(100+1, vector<int> (N+1, -1));
int num_coins, money;
vector<int> coins;

int recur(int money, int index) {
	if (money == 0)
		return 0;
	else if (money < 0)
		return inf;
	else if (index < 0)
		return inf;
	else if (dp[index][money] != -1)
		return dp[index][money];
	else if (money % coins[index] == 0)
		return dp[index][money] = money/ coins[index];
	return dp[index][money] = min({inf, 1+recur(money-coins[index], index), recur(money, index-1)});
}

void iterate() {
	// if money is 0, num of coins req is 0
	for (int i = 0; i < dp.size(); i += 1)
		dp[i][0] = 0;
	for (int j = 0; j < dp[0].size(); j += 1)
		dp[0][j] = (j % coins[0] == 0 ? j/coins[0]: inf);

	for (int money = 1; money < dp[0].size(); money += 1) {
		for (int index = 1; index < dp.size(); index += 1) {
			// dp[index][money] = min({inf, 1+dp[money-]})
			dp[index][money] = dp[index-1][money];
			if (money-coins[index] >= 0)
				dp[index][money] = min(dp[index][money], 1+dp[index][money-coins[index]]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> num_coins >> money;
	coins.resize(num_coins);
	for (auto &coin: coins)
		cin >> coin;
	sort(all(coins));

	iterate();
	// 	int ans = recur(money, num_coins-1	);
	int ans = dp[num_coins-1][money];
	cout << (ans < inf ? ans: -1) << '\n';

	return 0;
}
