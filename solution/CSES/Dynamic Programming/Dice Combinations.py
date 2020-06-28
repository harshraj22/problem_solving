# https://cses.fi/problemset/task/1633

n, mod = int(input()), 10**9 + 7

dp = [0 for _ in range(n+1)]
dp[0], dp[1] = 1, 1

for i in range(2, n+1):
	for j in range(1, 7):
		dp[i] += dp[i-j] if i - j >= 0 else 0
	dp[i] %= mod

print(dp[-1])
