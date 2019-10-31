# https://www.hackerrank.com/challenges/permutation-equation/problem

import os
import sys

fptr = open(os.environ['OUTPUT_PATH'], 'w')

numberOfElements = int(input())
elements = list(map(int, input().strip().split()))

solution = [None for _ in range(numberOfElements)]
for index in range(1, numberOfElements+1):
    for i in range(numberOfElements):
        if elements[elements[i]-1] == index:
            solution[index-1] = i + 1 
            break

fptr.write('\n'.join(map(str, solution)) + "\n")
fptr.close()