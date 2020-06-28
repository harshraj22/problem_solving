# https://cses.fi/problemset/task/1083

from functools import reduce

n, expected_xor = int(input()), 0

for i in range(n+1):
	expected_xor ^= i

nums = list(map(int, input().split()))
expected_xor ^= reduce(lambda x, y: x^y, nums)

print(expected_xor)
