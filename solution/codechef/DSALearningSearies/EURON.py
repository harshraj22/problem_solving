# https://www.codechef.com/LRNDSA04/problems/EURON
# Counting inversions using divide and conquer

# Bad problem statement: 
#   Not stated how to handle duplicates
from bisect import bisect_left
from math import inf

inversions = []

# @params: 
#   nums: list of tuple of (value, index)
# @returns:
#   same list of tuples sorted, updating the inversion counts
#       from the input list of tuples
def solve(nums):
    global inversions
    if len(nums) == 1:
        return nums
    # recursively solve for left, right subarray
    mid = len(nums)//2
    left, right = solve(nums[:mid]), solve(nums[mid:])
    # merge left and right subarry counting inversionsersions
    # for nums that who pair up across the partition
    for value, index in left:
        inversions[index] += bisect_left(right, (value, -inf))

    return sorted(left + right)

# Driver function for input/ output
def main():
    global inversions
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    inversions = [0 for _ in range(n)]
    data = [(num, index) for index, num in enumerate(nums)]
    solve(data)
    print(sum(inversions))

if __name__ == '__main__':
    main()