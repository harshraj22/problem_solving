# https://www.codechef.com/problems/GOOGOL05
# implementation of std::map

words = dict()
for _ in range(int(input())):
	word = input().strip()
	try:
		words[word] += 1
	except:
		words[word] = 1

for key, value in sorted(words.items()):
	print(key, value)
