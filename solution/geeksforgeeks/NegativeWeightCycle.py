# https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0

from math import inf

vertices, edges = 0,0
graph = [[] for _ in range(101)]
dist = [inf for _ in range(101)]

def initialise():
	global graph, dist
	for index, val in enumerate(graph):
		graph[index] = []
	for index, val in enumerate(dist):
		dist[index] = inf

def bellman_ford():
	global vertices, edges, graph, dist
	ans = False
	for index in range(vertices):
		for neighbour in graph[index]:
			if dist[neighbour[1]] > dist[index] + neighbour[0]:
				ans = True
				dist[neighbour[1]] = dist[index] + neighbour[0]
	return ans

def solve():
	global vertices, edges, graph
	vertices, edges = map(int, input().split())
	details = list(map(int, input().split()))
	dist[0] = 0
	for index in range(edges):
		source, dest, weight = details[index*3:index*3+3]
		graph[source].append((weight, dest))	
		# print(source, dest, weight)
	for _ in range(1,vertices):
		bellman_ford()
	print(1 if bellman_ford() is True else 0)
	# print(dist)
	# print(graph)

if __name__=='__main__':
	test = int(input())
	for tests in range(test):
		initialise()
		solve() 