# https://www.codechef.com/AUG19A/problems/ENCODING

md = 1000000007
l= []

def precompute():
	global l

	l.append(1)
	for i in range(10**6):
		l.append(0)
	for i in range(1,10**6):
		l[i]=l[i-1]*10
		l[i]%=md


def equal(s):
	global l
	lent = len(s)
	prev = [1 for __ in range(lent+1)]
	another = [0 for __ in range(lent)]
	another[0] = int(s[0])
	for i in range(1,lent):
		another[i] = ((another[i-1]-1)*10+(int(s[i])+1))
		another[i]%=md
		# another[i]=(md + another[i])
	prev[lent-1] = int(s[-1])+1

	for i in range(lent-2,-1,-1):
		prev[i] = prev[i+1]+(l[lent-i-1])*(int(s[i]))
		prev[i]%=md
		# prev[i] = prev[i+1]+(int(10**(lent-i-1)))*(int(s[i]))
		# prev[i]=(md+prev[i])

	ans,var,num=0,0,0
	for i in range(1,lent):
		if s[i]!=s[i-1]:
			if i>1 and another[i-2]>0:	# relaxed prefix
				# ans += ((another[i-2]-1)*int(10**(lent-i-1)))*45*int(10**(lent-i-1))
				# ans += (another[i-2]-1)*l[lent-i-1]*45*l[lent-i-1]
				ans += (another[i-2]-1)*l[lent-i-1]*45*l[lent-i-1]

			if int(s[i-1]) > int(s[i]):	# 97 then upto 88
				num = int(s[i-1])-1
			else:	# 79 then upto 77
				num = int(s[i-1])

			# constraint prefix
			# ans += (((num*(num+1))//2)*(int(10**(lent-i-1))))*(int(10**(lent-i-1)))
			ans += (((num*(num+1))//2)*l[lent-i-1])*l[lent-i-1]

		else:	# 77
			num = int(s[i])
			# constraint prefix and s[]
			# ans += num*(int(10**(lent-i-1)))*prev[i+1]
			ans += num*(l[lent-i-1])*prev[i+1]

			num -= 1
			# ans += (((num*(num+1))//2)*(int(10**(lent-i-1))))*int(10**(lent-i-1))
			ans += (((num*(num+1))//2)*(l[lent-i-1])*l[lent-i-1])

			if i>1 and another[i-2]>1:	# relaxed prefix
				ans += (another[i-2]-1)*l[lent-i-1]*45*l[lent-i-1]
				# ans += (another[i-2]-1)*int(10**(lent-i-1))*45*int(10**(lent-i-1))
		var = (var+ans)
		ans = 0

	return (var%md+md)%md

def sol(b):
	s = str(b)
	eq = equal(s)
	v = (b*(b+1))//2 - eq
	if len(s)>2:
		ss = '1'*(len(s)-2)
		if len(s)-3 > 0:
			ss += ('0'*(len(s)-3))
		bg = int(ss)
		v -= (bg*45)
		v = (v%md+md)%md
	elif len(s)==2:
		pass
	# print(v,' and ',(v+md)%md)
	# print(eq)
	return v

def solve():
	nl,l = input().strip().split()
	l = int(l)
	nr,r = input().strip().split()
	r = int(r)
	print((sol(r)-sol(l-1)+md)%md)
	# print(md)
	

if __name__=='__main__':
	precompute()
	for _ in range(int(input().strip())):
		solve()

'''
1
1 1
18 555444775544555444
219055319 : ans


1
18 100000000000000001
18 555444775544555444
301905305 : ans
'''