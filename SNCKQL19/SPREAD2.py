for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	t,i,c,j = a[0],1,0,1
	k = 0
	while(i < n):
		c += 1
		i += t
		t += sum(a[j:i])
		j = i
		# print(i,j,t)
		k += 1
	print(c)
	# 	print(i,j,n - (i))
	# 	n -= i
	# 	if (n <= 0):break
	# 	i += sum(a[j:j + i])
	# 	j = i
	# 	c += 1
	# print(c)
