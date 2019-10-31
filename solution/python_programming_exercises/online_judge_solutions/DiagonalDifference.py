# https://www.hackerrank.com/challenges/diagonal-difference/problem

import os
import sys

fptr = open(os.environ['OUTPUT_PATH'], 'w')

numOfRows = int(input().strip())
matrix = [[] for _ in range(numOfRows)]
for row in range(numOfRows):
	matrix[row] = list(map(int, input().strip().split()))
sum1, sum2 = 0,0
for i in range(numOfRows):
	for j in range(numOfRows):
		if i == j:
			sum1 += matrix[i][j]
		if numOfRows - 1 - i == j:
			sum2 += matrix[i][j]

fptr.write(str(abs(sum2 - sum1)) + "\n")
fptr.close()
# print(sum1, sum2)