for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	if(max(a) == -1) :print('inf')
	else:
		c,d = a[0] + 1,1
		ans = -1
		f = False
		for i in range(1,n - 1):
			# print(a[i])
			# print(a[i],c)
			# print(a[i],c,d)
			if(a[i] == c or a[i] == d):
				c,d = a[i] + 1,1
				# print(c,a[i])
				if(a[i + 1] == 1):
					ans = max(ans,a[i])
			elif(a[i] != c and a[i] != d and a[i] != -1):
				# print(a[i],c,d)
				# print('hello')
				f = True
			if(a[i] == -1):
				# print(a[i])
				c += 1
				# print(c)
		if ans == -1:print('inf')
		else:
			print('impossible') if f else print(ans)
			# if(a[i] == -1 and a[i - 1] != -1)
