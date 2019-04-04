for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	dp = {}
	ans = -99999999
	for i in range(k):
		dp[i] = []
		j = i
		temp_sum = 0
		while(j < len(a)):
			# temp_sum += a[j]
			dp[i].append(a[j])
			j += k
	for i in range(len(dp)):
		# print(len(dp[i]) - 1)
		for j in range(len(dp[i]) - 2, -1, -1):
			dp[i][j] += dp[i][j + 1]
			# print(dp[i][j])
	for i in range(n):
		index = (i // k)
		current = i % k
		# print(current, prev)
		# print(i, current)
		temp = dp[current][index]
		# if(index - 1 > -1):
		# 	temp -= dp[current][index - 1]
		# print('temp ', temp)
		ans = max(ans, temp)
		# ans = max(dp[current][i] - dp[current][prev], ans)
	# print(dp)
	print(ans)
	# ans = -9999999
	# for i in range(len(a)):
	# 	j = i
	# 	temp_sum = 0
	# 	while(j < len(a)):
	# 		temp_sum += a[j]
	# 		j += k
	# 	ans = max(ans, temp_sum)
	# print(ans)