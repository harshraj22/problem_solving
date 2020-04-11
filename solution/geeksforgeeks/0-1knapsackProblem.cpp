// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

const int N = 1e3 + 4;
vector<int> weight, value;
int dp[N][N], n, maxWeightCapacity;

// returns the max value that can be achieved
// using items from first 'index' number of items
// with total weight not exceeding 'weightAllowed'
int knapsack(int weightAllowed, int index) {
	if (weightAllowed < 0)
		return -1e8;
	else if (weightAllowed == 0 || index < 0)
		return 0;
	else if (dp[weightAllowed][index] != -1)
		return dp[weightAllowed][index];

	// max of: (if value at 'index' is excluded, value at 'index' is included)
	return dp[weightAllowed][index] = max(knapsack(weightAllowed, index-1),
								 value[index] + knapsack(weightAllowed-weight[index], index-1));
}

void solve(){
	for (int i = 0; i < N; i += 1) {
		fill(dp[i], dp[i]+N, -1);
	}

	cin >> n >> maxWeightCapacity;

	weight.resize(n);	
	value.resize(n);

	for (auto &it: value)
		cin >> it;

	for (auto &it: weight)
		cin >> it;

	cout << knapsack(maxWeightCapacity, n-1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}


/* 

# Python Implementation: Doesn't pass due to their bad testcase style (read comment section)

from math import inf

dp, weights, values = [[]], [], []
N, n, maxAllowedWeight = 10**3 + 5, 0, 0

def knapsack(allowedWeight, index):
    global dp, weights, values
    if allowedWeight < 0:
        return -inf
    elif allowedWeight == 0 or index < 0:
        return 0
    elif dp[allowedWeight][index] != -1:
        return dp[allowedWeight][index]
    dp[allowedWeight][index] = max(knapsack(allowedWeight, index-1), values[index] + knapsack(allowedWeight - weights[index], index-1))

    return dp[allowedWeight][index]

def solve():
    global dp, weights, values, n
    # initiaize the dp table
    dp = [[-1 for _ in range(N)] for __ in range(N)]

    n = int(input())
    maxAllowedWeight = int(input())

    values = list(map(int, input().strip().split()))
    weights = list(map(int, input().strip().split()))

    print(knapsack(maxAllowedWeight, n-1))
    for i in range(n):
        print(dp[i][:n])
    print(f'values: {values}')
    print(f'weights: {weights}')


if __name__ == '__main__':
    tests = int(input())
    for test in range(tests):
        solve()
*/