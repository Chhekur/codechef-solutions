for _ in range(int(input())):
	tr = int(input())
	tra = [int(x) for x in input().split()]
	dr = int(input())
	dra = [int(x) for x in input().split()]
	ts = int(input())
	tsa = [int(x) for x in input().split()]
	ds = int(input())
	dsa = [int(x) for x in input().split()]
	f = 0
	for i in tsa:
		if i not in tra:f = 1
	for i in dsa:
		if i not in dra:f = 1
	print("no") if f == 1 else print("yes")