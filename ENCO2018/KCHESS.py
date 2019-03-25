def chek(m,x,y):
	for i in m:
		# print(i)
		if(x-2 == i[0] and y-1 == i[1]) or (x-1 == i[0] and y-2 == i[1]) or (x+1 == i[0] and y-2 == i[1]) or (x+2 == i[0] and y-1 == i[1]) or (x-2 == i[0] and y+1 == i[1]) or (x-1 == i[0] and y+2 == i[1]) or (x+2 == i[0] and y+1 == i[1]) or (x+2 == i[0] and y+2 == i[1]):
			# print(i)
			return True
	return False

for _ in range(int(input())):
	n = int(input())
	m = []
	for _ in range(n):
		m.append([int(x) for x in input().split()])
	x,y = [int(x) for x in input().split()]
	a = chek(m,x,y)
	b = chek(m,x - 1, y)
	c = chek(m,x + 1, y)
	d = chek(m, x, y - 1)
	e = chek(m, x, y + 1)
	f = chek(m, x - 1, y - 1)
	g = chek(m, x - 1, y + 1)
	h = chek(m, x + 1, y - 1)
	i = chek(m, x + 1, y + 1)
	# print(b,c,d,e,f,g,h,i)
	if(a):print('YES')
	elif(b and c and d and e and f and g and h and i):print('YES')
	else: print('NO	')