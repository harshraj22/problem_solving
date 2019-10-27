# https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/polygon-possible/
# Refer : https://www.geeksforgeeks.org/check-if-it-is-possible-to-create-a-polygon-with-given-n-sides/
for _ in range(int(input())):
    n = int(input())
    sides = list(map(int, input().strip().split()))

    print("Yes" if max(sides) < sum(sides) - max(sides) else "No")