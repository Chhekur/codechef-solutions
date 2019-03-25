for _ in range(int(input())):
	n,m,x,y = [int(x) for x in input().split()]
	f = 0
	a,b = (n - 1) % x, (m - 1) % y
	if (n == 1 and m == 1) or (n == 2 and m == 2) or (x == 1 and y == 1): f = 1
	elif (a == 0 and b == 0) or (a == 1 and b == 1): f = 1
	elif (a == 1 and m == 2) or (n == 2 and b == 1) or (a == 0 and m == 1) or (n == 1 and b == 0) or (x == 1 and (b == 0 or b == 1) and n > 1) or (y == 1 and (a == 0 or a == 1) and m > 1):f = 1
	print("Chefirnemo") if f == 1 else print("Pofik")