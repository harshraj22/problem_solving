from math import sqrt

if __name__=='__main__' :	
	l = list(map(int,input().strip().split(',')))
	c,h = 50,30
	sq = lambda x: int(sqrt((2*c*x)/h))
	ans = list(map(sq,l))
	for i in ans:
		print(i,end=',')
	print()
	# print(ans)

# Question 6
# Level 2

# Question:
# Write a program that calculates and prints the value according to the given formula:
# Q = Square root of [(2 * C * D)/H]
# Following are the fixed values of C and H:
# C is 50. H is 30.
# D is the variable whose values should be input to your program in a comma-separated sequence.
# Example
# Let us assume the following comma separated input sequence is given to the program:
# 100,150,180
# The output of the program should be:
# 18,22,24

# Hints:
# If the output received is in decimal form, it should be rounded off to its nearest value (for example, if the output received is 26.0, it should be printed as 26)
# In case of input data being supplied to the question, it should be assumed to be a console input. 

# Solution:
# #!/usr/bin/env python
# import math
# c=50
# h=30
# value = []
# items=[x for x in raw_input().split(',')]
# for d in items:
#     value.append(str(int(round(math.sqrt(2*c*float(d)/h)))))

# print ','.join(value)