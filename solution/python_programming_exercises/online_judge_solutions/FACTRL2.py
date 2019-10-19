# https://www.codechef.com/problems/FCTRL2

# precalculate factorials
fact = [1,1]
for i  in range(2,101):
    fact.append(i*fact[-1])

for _ in range(int(input().strip())):
    n = int(input().strip())
    print(fact[n])