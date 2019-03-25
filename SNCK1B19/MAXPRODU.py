for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	if(k * (k + 1)//2  > n):print(-1)
	else:
		a = []
		min_sum = k * (k + 1) // 2
		remain = n - min_sum
		# for i in range(1,k + 1):
		# 	a.append(i)
		# print(a)
		e_diff = remain // k
		for i in range(1,k + 1):
			a.append(i + e_diff)
		# print(a)
		still_remain = remain % k
		for i in range(k - 1,-1,-1):
			if(still_remain > 0):
				a[i] += 1
				still_remain -= 1
			else:break
		# print(a)
		ans = 1
		for i in a:
			ans = (ans * i * (i - 1) ) % 1000000007
		print(ans)