# https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/charges-repel/

n = int(input())
s = input()
last, cnt, ans = "*", 0, []
for i in range(len(s)):
    try:
        if ans[-1] == s[i]:
            ans.pop()
        else:
            ans.append(s[i])
    except:
        ans.append(s[i])
ans = ''.join(ans)
print(len(ans))
