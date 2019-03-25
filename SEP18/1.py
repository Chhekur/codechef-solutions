for _ in range(int(input())):
	n,x,s = [int(x) for x in input().split()]
	for _ in range(s):
		a,b = [int(x) for x in input().split()]
		if a == x: x = b
		elif b == x: x = a
	print(x)
