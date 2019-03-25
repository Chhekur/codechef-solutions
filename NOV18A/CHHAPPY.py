for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	dp = {}
	for i in range(n):
		if dp.get(a[i]):dp[a[i]].append(i + 1)
		else : dp[a[i]] = [i + 1]
	flag = 0
	for i in dp:
		count = 0
		for j in dp[i]:
			if dp.get(j):count += 1
		if(count > 1):
			flag = 1
			break
	print('Truly Happy') if flag == 1 else print('Poor Chef')