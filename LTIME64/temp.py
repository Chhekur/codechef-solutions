for _ in range(int(input())):
	n,m = [int(x) for x in input().split()]
	op = []
	for _ in range(n):
		op.append([int(x) for x in input().split()])
	op.sort()
	for _ in range(m):
		p = int(input())
		ans = -1
		for i in range(len(op) - 1):
			if(p >= op[i][0] and p < op[i][1]):
				# print(0)
				# print('p',p)
				ans = 0
				# break
			# else:
			elif(p >= op[i][0] and p >= op[i][1]):
				# print('p',p)
				if(i >= (len(op) - 1)):ans = -1
				ans = abs(op[i + 1][0] - p)
				# break
		print(ans)