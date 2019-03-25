for _ in range(int(input())):
	n,m = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	e,f = [],[]
	c,d = 0,0
	n1,n2 = 0,0
	for i in a:
		if(i > 0):
			e.append(i)
			c += 1
		if(i == 1):n1 += 1
	for i in b:
		if(i > 0):
			f.append(i)
			d += 1
		if(i == 1):n2 += 1
	e.sort()
	f.sort()
	if(c == 0 and d == 0):print('Bob')
	elif(len(e) != len(f)):print('Alice')
	elif(len(e) == len(f) and e == f):print('Bob')
	else:print('Alice')