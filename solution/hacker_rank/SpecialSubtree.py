# https://www.hackerrank.com/challenges/primsmstsub/problem

import heapq
import os
import sys

N = 3000 + 5
n, m = 0, 0
graph = [[] for _ in range(N)]
rank = [1 for _ in range(N)]
parent = [i for i in range(N)]

fptr = open(os.environ['OUTPUT_PATH'], 'w')

def find_par(x):
    if parent[x] == x:
        return x
    var = find_par(parent[x])
    parent[x] = var
    return parent[x]

def add_into(x, y):
    xp, yp = find_par(x), find_par(y)
    if rank[xp] > rank[yp]:
        parent[yp] = xp
        rank[xp] += rank[yp]
    else:
        parent[xp] = yp
        rank[yp] += rank[xp]

if __name__=='__main__':
    # global n, m
    n, m = map(int, input().strip().split())

    weights = []

    for _ in range(m):
        x, y, weight = map(int, input().strip().split())
        graph[x].append((weight, y))
        graph[y].append((weight, x))
        weights.append((weight, x, y))

    heapq.heapify(weights)
    ans = 0

    input()

    while len(weights) > 0:
        weight, x, y = heapq.heappop(weights)
        if find_par(x) == find_par(y):
            continue
        else:
            add_into(x, y)
            ans += weight

    # print(ans)
    fptr.write(str(ans) + '\n')
    fptr.close()