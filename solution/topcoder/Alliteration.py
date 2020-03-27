https://vjudge.net/problem/TopCoder-6808

class Alliteration():
	def __init__(self):
		pass

	def count(self, String):
		# arr = [0 for _ in range(26)]
		ans, cur = 0, 1
		for index, word in enumerate(String):
			if index is 0:
				continue
			elif word[0].lower() == String[index -1][0].lower():
				cur += 1
			else:
				if cur > 1:
					ans += 1
				cur = 1
		if cur > 1:
			ans += 1
		return ans

# myObj = Alliteration() 
# inp = ["Round", "the", "rugged", "rock", "the", "ragged", "rascal", "ran"]

# print(myObj.count(inp))