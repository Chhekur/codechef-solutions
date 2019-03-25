for _ in range(int(input())):
	pl1,pl2,k = [int(x) for x in input().split()]
	a = (pl1 + pl2) // k
	print('CHEF') if(a % 2 == 0) else print('COOK')