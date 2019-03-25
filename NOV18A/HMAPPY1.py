n,q,k = [int(x) for x in input().split()]
s = [int(x) for x in input().split()]
b, t,l,r,p = [], 0, 0, 0,s[0]
if s[0] == 1:t = 1
for i in range(1,n):
	if(s[i] == 1 and s[i] == p):
		t += 1
		r += 1
	else:
		if(t > 0): b.append([t,l,r])
		if s[i] == 1: t,l,r = 1,i,i
		else: t = 0
	p = s[i]
	

if(t > 0):
	b.append([t,l,r])
# print(b)
if(s[0] == s[n - 1] and s[0] == 1):
	b[0][0] += b[len(b) - 1][0]
	b[0][1] = b[len(b) - 1][1]
	if(len(b) > 1): b.pop()
b.sort(reverse = True)
q = input()
for i in q:
	if i == '!' and len(b) > 0:
		b[0][1] = (b[0][1] + 1) % n
		b[0][2] = (b[0][2] + 1) % n
	elif i == '?':
		# print(len(b))
		# print(b)
		if(len(b) > 0):
			if b[0][2] < b[0][1]:
				if len(b) > 1:
					print(min(k,max(b[1][0], n - b[0][1] , b[0][2] + 1)))
				else:print(min(k,max(n - b[0][1], b[0][2] + 1)))
			else: print(min(k,b[0][0]))
		else: print(0)