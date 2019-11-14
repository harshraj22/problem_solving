import os
import sys

from datetime import datetime, timedelta

fptr = open(os.environ['OUTPUT_PATH'], 'w')

for _ in range(int(input())):
    t1, t2 = input(), input()
    time1 = datetime.strptime(t1, '%a %d %b %Y %X %z')
    time2 = datetime.strptime(t2, '%a %d %b %Y %X %z')
    difference = abs(time1 - time2)
    ans = str(int(difference.total_seconds()))
    fptr.write(ans + '\n')

fptr.close()
