# https://leetcode.com/problems/monotone-increasing-digits/

class Solution:
	def toInt(self, nums):
		return int(''.join(map(str, nums)))

	def monotoneIncreasingDigits(self, N: int) -> int:
		# if the number is strictly increasing, return the num

		# else decrease the peak point, and append 9 from the peak point to the end
		prev, nums, ans, reached = -1, [int(x) for x in str(N)], [], False

		# if N is just a bunch of 1 followed by a single 0, then reduce the length
		if nums[:-1].count(1) == len(nums) - 1 and nums[-1] == 0:
			return self.toInt([9] * len(nums[:-1]))

		for i, num in enumerate(nums):
			if reached:
				ans.append(9)
			elif num < prev:	# make the cur num less than N
				cur, i = ans[-1], i-1
				while i >= 0:
					if ans[i] == cur:
						i -= 1
					else:
						break
				# now, ans[i] != cur, so, replace ans[i+1] with ans[i+1]-1, and rest
				# all ahead of that with 9
				ans[i+1] -= 1
				ans[i+2:] = [9 for _ in ans[i+2:]]
				reached = True
				ans.append(9)
			else:
				ans.append(num)
			prev = num
		return int(''.join(map(str, ans)))

