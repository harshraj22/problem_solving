# https://www.codechef.com/problems/TSORT
import sys
l = []
for _ in range(int(sys.stdin.readline())):
    l.append(int(sys.stdin.readline()))
for i in sorted(l):
    print(i)