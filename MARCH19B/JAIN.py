for _ in range(int(input())):
	n = int(input())
	dp = {}
	strings = {}
	for k in range(n):
		f = {}
		s = input()
		for i in s:
			if(f.get(i)):f[i] += 1
			else: f[i] = 1
		strings[k] = f
		# print(f)
		has = ''
		req = ''
		for i in 'aeiou':
			if(f.get(i)):has += i
			else: req += i
		# print(has)
		if(dp.get(has)):dp[has][1] += 1
		else:dp[has] = [req, 1]
	# print(dp)
	count = 0
	for i in dp:
		d = list(dp[i][0])
		for j in dp:
			flag = 0
			for k in d:
				if(j.count(k) > 0):flag += 1
			if(flag == len(d)):
				# print(i,dp[i][1], j,dp[j][1])
				if(i == j):count += (dp[i][1] * (dp[j][1] - 1)) // 2
				else:count += dp[i][1] * (dp[j][1])
		dp[i][1] = 0
	print(count)

