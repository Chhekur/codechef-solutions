def fun (r):
	return ((2 + ((r - 1) * 2) ) // 2 ) * r
for _ in range(int(input())):
	l,r = [int(x) for x in input().split()]
	n = fun(r)
	n -= fun(l - 1)
	print(n)
