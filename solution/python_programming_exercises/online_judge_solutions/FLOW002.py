# https://www.codechef.com/problems/FLOW002
import sys
for _ in range(int(sys.stdin.readline())):
    a,b = map(int,sys.stdin.readline().split())
    print(a%b)