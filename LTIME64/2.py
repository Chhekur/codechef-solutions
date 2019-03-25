# def upper_bound(a, n,x) :
# 	l = 0
# 	h = n
# 	while (l < h):
# 		mid = (l + h) // 2
# 		if (x >= a[mid][0]) :
# 			l = mid + 1
# 		else :
# 			h = mid
# 	if(l < 0 or l >= n or x > a[l][0]):return -1
# 	return l

def lower_bound(a,n, x) :
	l = 0
	h = n
	while (l < h) :
		mid = (l + h) // 2
		if (x <= a[mid][0]):
			h = mid
		else :
			l = mid + 1
	# print(a[l][0])
	# print(l)
	if(l == n):return l - 1
	if(l < 0 or l >= n):return -1
	return l

for _ in range(int(input())):
	n,m = [int(x) for x in input().split()]
	op = []
	for _ in range(n):
		op.append([int(x) for x in input().split()])
	op.sort()
	# print(op)
	for _ in range(m):
		p = int(input())
		lo = lower_bound(op,len(op),p)
		# print('p',p)
		ans = -1
		# print('lo',lo)
		if lo == -1:ans = -1
		# elif lo >= n: ans = -1
		elif(p >= op[lo][0] and p < op[lo][1]):ans = 0
		elif(p <= op[lo][0]):
			if(p >= op[lo - 1][0] and p < op[lo - 1][1]):ans = 0
			else:
				if(lo - 1 < 0):
					ans = abs(op[lo][0] - p)
				else:
					ans = abs(p - op[lo][0])
		elif(p >= op[lo][1]):
			if(p >= op[lo + 1][0] and p < op[lo + 1][1]):ans = 0
			else:
				if((lo + 1) > (n - 1)): ans = -1
				else:
					ans = abs(op[lo + 1][1] - p)
		# else : ans = -1
		print(ans)

		# if(lo == -1):
		# 	up = upper_bound(op,len(op),p)
		# 	print('up',up)
		# 	if(up == -1):print(-1)
		# 	else:print(abs(op[up][0] - p))
		# else:
		# 	if(op[lo][1] > p):print(0)
		# 	else:
		# 		up = upper_bound(op,len(op),p)
		# 		print('up',up)
		# 		if(up == -1):print(-1)
		# 		else:print(abs(op[up][0] - p))
		# if(lo != -1 and lo < )
		# print(lo)
