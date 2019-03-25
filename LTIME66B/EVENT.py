day = ["saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"]

for _ in range(int(input())):
	a = [x for x in input().split()]
	# gap = abs(d[a[0]] - d[a[1]]) + 1
	l,r = int(a[2]),int(a[3])
	c,d = 0,0
	for i in range(len(day)):
		if(a[0] == day[i]): c = i
		if(a[1] == day[i]): d = i
	if(c == d):gap = 1
	elif(c < d): gap = d - c + 1
	# if(c < 7 and d < 7)
	else : gap = 7 - (c - d - 1)
	# print(gap)
	# if(l > gap and (r < (gap + 7) or r < gap)):print('impossible')
	# else:
	ans = 0
	c = 0
	if(gap >= l and gap <= r):
		c += 1
		ans = gap
	t = gap
	while c < 3 and t <= r:
		t += 7
		if(t >= l and t <= r):
				c += 1
				ans = t
	if(c > 1):print('many')
	elif c == 1:print(ans)
	else : print('impossible')