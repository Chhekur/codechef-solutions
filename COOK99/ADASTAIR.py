from math import ceil

for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	a.insert(0,0)
	# print(a)
	c = 0
	for i in range(1,n + 1):
		if abs(a[i] - a[i - 1]) > k:
			# print(abs(a[i] - a[i - 1]))
			if(abs(a[i] - a[i - 1]) % k == 0):
				c += (abs(a[i] - a[i - 1]) // k) - 1
			else: 
				c += abs(a[i] - a[i - 1]) // k
				# print(abs(a[i] - a[i - 1]))
				# print(c)
	print(c)
