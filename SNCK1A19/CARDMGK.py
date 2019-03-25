for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	f = False
	for i in range(1,n):
		if a[i] < a[i - 1]:f = True
	if not f:print('YES')
	else:
		s = str(a[0])
		j = 0
		for i in range(1,n):
			if a[i] < a[i - 1]:break
			s += str(a[i])
			j = i
		t = ""
		# print(s)
		for i in a[j + 1::]:
			t += str(i)
		# print(t)
		s = t + s
		f = False
		for i in range(1,n):
			if int(s[i]) < int(s[i - 1]) : f = True
		if f :print('NO')
		else:print('YES')
		# print(s)