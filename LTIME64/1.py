for _ in range(int(input())):
	n = int(input())
	count = 0
	for _ in range(n):
		a,b = [int(x) for x in input().split()]
		if(abs(a - b) > 5):count += 1
	print(count)