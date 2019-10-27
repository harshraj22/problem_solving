# https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/hamiltonian-and-lagrangian/
n = int(input())
arr = list(map(int, input().strip().split()))

ans, grtr = [], 0
for i in arr[::-1]:
    if i >= grtr:
        ans.append(i)
        grtr = i
for i in ans[::-1]:
    print(i, end = ' ')
print()