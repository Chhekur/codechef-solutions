for _ in range(int(input())):
	n,m = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	distinct_color = {}
	f, ans = 0, 0
	for i in range(n):
		# if(a[i] >= a[i + 1]):
		for j in range(i - 1, -1,-1):
			if(a[j] > a[i]):break
			else: a[j] = 0
	# print(a)
	for i in range(n):
		if(a[i] != 0):
			if not distinct_color.get(b[i]):
				distinct_color[b[i]] = 1
		# print(f)
		# if(a[i] - f < 0):
			# print('Hello')
		# f = a[i] - f
		# print(f)
	print(len(distinct_color))