for _ in range(int(input())):
	n = int(input())
	temp = (n - 1) // 26
	temp2 = n % 26
	ans = 2**temp
	if n == 0: print(1,0,0)
	elif temp2 > 0 and temp2 < 3: print(ans,0,0)
	elif temp2 > 2 and temp2 < 11: print(0,ans,0)
	else: print(0,0,ans)