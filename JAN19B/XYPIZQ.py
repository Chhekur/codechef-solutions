from math import gcd
for _ in range(int(input())):
	n,t,x,y,z = [int(a) for a in input().split()]
	t2 = (2 * n) + 1
	if t == 1:
		if y > x:
			if z == y - 1: t1 = (y - 1)
			elif z == y + 1: t1 = (t2 - (y + 1))
		else:
			if z == y + 1: t1 = (y + 1)
			elif z == y - 1: t1 = (t2 - (y - 1))
	elif t == 3:
		if y > x:
			if z == y - 1: t1 = y - 1
			elif z == y + 1: t1 = (t2 - (y - 1))
		else:
			if z == y - 1: t1 = (t2 - (y + 1))
			elif z == y + 1: t1 = y + 1
	elif t == 2 or t == 4:
		if z > y: t1 = t2 - (2 * (x + 1))
			# print(t1)
		else: t1 = t2 - (2 * (z + 1))
	a = gcd(t1,t2)
	# print(t1 / t2)
	# print(t1,t2)
	print(t1 // a, t2 //a)
