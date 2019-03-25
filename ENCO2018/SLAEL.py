for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	dp = {}
	# for i in range()
	for i in range(n):
		first,second = 0,0
		for j in range(i,n):
			if (a[j] > first):
				second = first
				first = a[j]
			elif (a[j] > second and a[j] != first):
				second = a[j]
			if dp.get(second):dp[second] = max(dp[second], (j - i) + 1)
			else: dp[second] = (j - i) + 1
		# print(second)
	ans = 0
	print(dp)
	for i in dp:
		if(k >= i):ans = max(ans, dp[i])
	print(ans)