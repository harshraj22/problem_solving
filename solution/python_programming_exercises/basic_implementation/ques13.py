if __name__=='__main__' :
	s = input().strip()
	LETTERS = sum(1 if x.isalpha() else 0 for x in s)
	DIGITS = sum(1 if x.isdigit() else 0 for x in s)
	print('LETTERS ',LETTERS)
	print('DIGITS ',DIGITS)


# Question 13
# Level 2

# Question:
# Write a program that accepts a sentence and calculate the number of letters and digits.
# Suppose the following input is supplied to the program:
# hello world! 123
# Then, the output should be:
# LETTERS 10
# DIGITS 3

# Hints:
# In case of input data being supplied to the question, it should be assumed to be a console input.

# Solution:
# s = raw_input()
# d={"DIGITS":0, "LETTERS":0}
# for c in s:
#     if c.isdigit():
#         d["DIGITS"]+=1
#     elif c.isalpha():
#         d["LETTERS"]+=1
#     else:
#         pass
# print "LETTERS", d["LETTERS"]
# print "DIGITS", d["DIGITS"]