for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	dp,e,o = {},0,0
	for i in a:
		if dp.get(i):dp[i] += 1
		else: dp[i] = 1
		if i % 2 == 0: e += 1
		else: o += 1
	invalid_pair = 0
	# print(dp)
	for i in dp:
		if dp[i] > 1:invalid_pair += ((dp[i]) * (dp[i] - 1) // 2)
		# elif dp[i] > 1: invalid_pair += dp[i] - 1
	for i in dp:
		z = i ^ 2
		# print(z)
		if dp.get(z) and dp[z] > 0:
			invalid_pair += dp[i] * dp[z]
			dp[z] = 0
			dp[i] = 0
	print(invalid_pair)
	total_pair = e*(e - 1) // 2 + o*(o - 1) // 2
	print(total_pair - invalid_pair)