from collections import defaultdict

def ispower(s):
	# returns if s is a power of 5
	n =  int(s,2)
	if n == 0:
		return True
	while n%5==0:
		n/=5

	return True if n==1 else False

record = defaultdict(lambda :-1)

def get(s):
	# print(f'for {s} ispower : {ispower(s)}')
	if s[0]=='0':
		record[s] = 100
		return 100
	elif ispower(s):
		record[s] = 1
		return 1
	elif record[s] != -1:
		return record[s]

	ans = 100
	for index,val in enumerate(s):
		if index==0:
			continue
		ans = min(ans,get(s[:index])+get(s[index:]))

	record[s] = ans
	return ans


class CuttingBitString:
	def __init__(self):
		pass

	def getmin(self, s):
		ans = get(s)
		return -1 if ans > 1+len(s) else ans


# obj = CuttingBitString()
# print(obj.getmin(input()))