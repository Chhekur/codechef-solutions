for _ in range(int(input())):
	n,x = [int(x) for x in input().split()]
	dp = {}
	s = input()
	dp[x] = 1
	for i in s:
		if(i == "R"): x += 1
		else:x -= 1
		if(not dp.get(x)):dp[x] = 1
	print(len(dp))