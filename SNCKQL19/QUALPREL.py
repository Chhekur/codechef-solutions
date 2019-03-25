for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	a.sort(reverse = True)
	m,c = a[k - 1],0
	# print(m,k - 1)
	for i in a:
		if(i >= m):c += 1
	print(c)