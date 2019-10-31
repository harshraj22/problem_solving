# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the beautifulDays function below.
def beautifulDays(i, j, k):
    ans = 0
    for days in range(i, j+1):
        day = int(str(days)[::-1])
        
        if abs(day-days)%k == 0:
            ans += 1

    return ans


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ijk = input().split()

    i = int(ijk[0])

    j = int(ijk[1])

    k = int(ijk[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
