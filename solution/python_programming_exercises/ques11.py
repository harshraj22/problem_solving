if __name__=='__main__' :
	convert = lambda s: int(s,2)	
	check = lambda x: True if x%5==0 else False
	l = list(map(str,input().strip().split(',')))
	sol = [c for c in l if check(convert(c))]
	print(','.join(sol))


# Question 11
# Level 2

# Question:
# Write a program which accepts a sequence of comma separated 4 digit binary numbers as its input and then check whether they are divisible by 5 or not. The numbers that are divisible by 5 are to be printed in a comma separated sequence.
# Example:
# 0100,0011,1010,1001
# Then the output should be:
# 1010
# Notes: Assume the data is input by console.

# Hints:
# In case of input data being supplied to the question, it should be assumed to be a console input.

# Solution:
# value = []
# items=[x for x in raw_input().split(',')]
# for p in items:
#     intp = int(p, 2)
#     if not intp%5:
#         value.append(p)

# print ','.join(value)