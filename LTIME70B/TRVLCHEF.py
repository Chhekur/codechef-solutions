for _ in range(int(input())):
	n,d = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	q = [0]
	dp = {0:1}
	while(len(q) > 0):
		u = q[0]
		q.pop(0)
		for i in range(len(a)):
			if(abs(a[u] - a[i]) <= d):
				if(not dp.get(i)):
					dp[i] = 1
					q.append(i)
					break
		# break
		# print(q)
	# print(q, dp)
	if(len(dp) == n):print('YES')
	else:print('NO')