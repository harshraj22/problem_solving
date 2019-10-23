# https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-welcome-problem/
import sys

N = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))
B =  list(map(int, sys.stdin.readline().split()))
for i in [x + y for x, y in zip(A, B)]:
    print(i, end = ' ')

print()