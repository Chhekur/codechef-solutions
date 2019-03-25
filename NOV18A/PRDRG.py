dp = [0,1]
for i in range(2,26):
	if i % 2 == 0: dp.append(2 * dp[i - 1] - 1)
	else: dp.append(2 * dp[i - 1] + 1)

t = [int(x) for x in input().split()]
for i in t[1::]:
	print(dp[i],2**i, end = ' ')