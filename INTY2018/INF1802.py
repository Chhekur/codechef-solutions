for _ in range(int(input())):

	n,q = [int(x) for x in input().split()]


	a = [int(x) for x in input().split()]


	dp = {i:a[0] for i in range(n+1)}


	for j in range(n):
		for i in range(j+1, n, j+1):
			dp[j] += a[i]


	for _ in range(q):
		k = int(input())
		print(dp[k])