# https://www.codechef.com/problems/INTEST
n,k = map(int,input().strip().split())
ans = 0
for _ in range(n):
    t = int(input().strip())
    if t%k is 0:
        # remember ans = ans + 1 creates a local variable
        ans += 1
print(ans)