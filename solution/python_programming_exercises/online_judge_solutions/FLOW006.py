# https://www.codechef.com/problems/FLOW006
for _ in range(int(input().strip())):
    n,ans = input(),0
    for i in n:
        ans += int(i)
    print(ans)
