for _ in range(int(input())):
	n,a,b = [int(x) for x in input().split()]
	s = [int(x) for x in input().split()]
	x,y,z = 0,0,0
	for i in s:
		if i % a == 0: x += 1
		if i % b == 0: y += 1
		if (i % a == 0) and (i % b == 0): z += 1
	if z == 0:
		print('ALICE') if x <= y else print('BOB')
	else:
		print('BOB') if y <= x else print('ALICE')