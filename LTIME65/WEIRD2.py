for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	dp = {}
	for i in a:
		if(dp.get(i)):dp[i] += 1
		else: dp[i] = 1
	ans = 0
	b = []
	for i in dp:
		if(dp[i] >= i):ans += 1
		b.append((dp[i],i))
	a = list(dp)
	# print(b)
	# b.sort(reverse = True)
	# print(a)
	a.sort()
	# print(b)
	# print(a)
	for i in range(len(b)):
		for j in range(i + 1,len(b)):
			if(dp[a[i]] >= a[j] and dp[a[j]] >= a[i]):ans += 2
			elif(dp[a[i]] < a[j]) :break
	# for i in range(len(b)):
	# 	for j in range(i + 1,len(b)):
	# 		if(dp[b[i][1]] >= b[j][1] and dp[b[j][1]] >= b[i][1]):ans += 2
	# 		elif(dp[b[j][1]] < b[i][1]) :break
	print(ans)