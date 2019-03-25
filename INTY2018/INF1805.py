for _ in range(int(input())):
	n,q = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	for _ in range(q):
		k = int(input())
		sum = 0
		# if(k == 0):k = 1
		for i in range(0,n,k + 1):
			sum += a[i]
		print(sum)