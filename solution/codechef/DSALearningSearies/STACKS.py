# https://www.codechef.com/LRNDSA04/problems/STACKS
# Basic binary search

from bisect import bisect_right
# bisect_right is equivalent to upper_bound in cpp

def solve():
    n, stack = int(input()), []
    nums = list(map(int, input().split()))

    for num in nums:
        index = bisect_right(stack, num)
        if index == len(stack):
            stack.append(num)
        else:
            stack[index] = num
    # *stack : this is called tuple unpacking
    print(len(stack), *stack)

def main():
    tests = int(input())
    for test in range(tests):
        solve()

if __name__ == '__main__':
    main()