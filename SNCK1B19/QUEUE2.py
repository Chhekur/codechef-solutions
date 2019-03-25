for _ in range(int(input())):
	n,m,k,l = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	a.append(k)
	a.sort()
	wait = (m + 1) * l
	# print(wait)
	for i in a:
		d = i // l
		r = m - d
		# print(i,r, d, i % l)
		if(r > -1):t_wait = r * l + (l - (i % l))
		else: t_wait = 0
		m += 1
		wait = min(wait,t_wait)
		# print(wait)
	print(wait)
		# else:t_wait = ()

