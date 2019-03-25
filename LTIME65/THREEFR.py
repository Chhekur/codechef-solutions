for _ in range(int(input())):
	x,y,z = [int(x) for x in input().split()]
	a = x + y - z
	b = x + z - y
	c = y + z - x
	print('yes') if(a == 0 or b == 0 or c == 0) else print('no')