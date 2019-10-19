if __name__=='__main__' :
	s = input().strip()
	upper = sum(1 if x.isupper() else 0 for x in s)
	lower = sum(1 if x.islower() else 0 for x in s)
	print('upper ',upper)
	print('lower ',lower)


# Question 14
# Level 2

# Question:
# Write a program that accepts a sentence and calculate the number of upper case letters and lower case letters.
# Suppose the following input is supplied to the program:
# Hello world!
# Then, the output should be:
# UPPER CASE 1
# LOWER CASE 9

# Hints:
# In case of input data being supplied to the question, it should be assumed to be a console input.

# Solution:
# s = raw_input()
# d={"UPPER CASE":0, "LOWER CASE":0}
# for c in s:
#     if c.isupper():
#         d["UPPER CASE"]+=1
#     elif c.islower():
#         d["LOWER CASE"]+=1
#     else:
#         pass
# print "UPPER CASE", d["UPPER CASE"]
# print "LOWER CASE", d["LOWER CASE"]