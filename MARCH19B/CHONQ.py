for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	# ans = 9999999999999
	pos = n + 1
	for i in range(len(a)):
		anger = 0
		div = 1
		for j in a[i::]:
			anger += j // div
			div += 1
		
		if(anger <= k):
			# ans = anger
			pos = i + 1
			break
	print(pos)