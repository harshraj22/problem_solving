# This is a copied solution
# https://www.codechef.com/viewsolution/26210996

import heapq
from sys import stdin
def reader():
    ans = []
    try:
        while True:
            p=stdin.read(1)
            terminals = set([' ','\n',''])
            while p not in terminals:
                ans.append(p)
                p=stdin.read(1)
                #print(ans)
            yield int("".join(ans))
            ans.clear()
    except:
        raise StopIteration()
def solve(k,n):
    h = []
    count = 0
    for i in range(0,n):
        x=next(r)
        if count<k:
            heapq.heappush(h,x)
            count+=1
        else:
            if x>h[0]:
                heapq.heappush(h,x)
                heapq.heappop(h)
        if count<k:
            print("-1",end=" ")
        else:
            print(h[0],end=" ")
r = reader()
t = next(r)
while t:
    k,n=next(r),next(r)
    solve(k,n)
    print()
    t-=1