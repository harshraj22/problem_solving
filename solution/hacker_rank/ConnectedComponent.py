# https://www.hackerrank.com/contests/data-structure-tasks-binary-tree-union-find/challenges/connected-component/problem

from sys import stdin

par, weight = [], []

nodes = int(input())
connected = nodes

par = [i for i in range(nodes+5)]
weight = [1 for i in range(nodes+5)]

def find_par(u):
    if par[u] == u:
        return u
    par[u] = find_par(par[u])
    return par[u]

def merge(u, v):
    up, vp = find_par(u), find_par(v)
    if weight[up] > weight[vp]:
        weight[up] += weight[vp]
        par[vp] = up
    else:
        weight[vp] += weight[up]
        par[up] = vp

for line in stdin:
    u, v = map(int, line.split())
    up, vp = find_par(u), find_par(v)
    if up == vp:
        print(connected, "CYCLE FORMED!")
    else:
        connected -= 1
        print(connected)
        merge(up, vp)