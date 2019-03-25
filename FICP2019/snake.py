def fun(m):
	visi = []
	dis = []
	for i in range(100):
		visi.append(0)
		dis.append(0)
	qu = []
	visi[0] = 1
	qu.append(0)
	while (len(qu) > 0):
		u = qu[0]
		if(u > 100):break
		qu.pop(0)
		# print(qu)
		for i in range(u+1, u + 7):
			# print(qu)
			# print(i, end = ' ')
			if(i < 100):
				# print(i)
				if(visi[i] == 0):
					visi[i] = 1
					# if(i == 99):print(dis[u])
					if(dis[i] != 0):
						dis[i] = min(dis[i], dis[u] + 1)
					else:
						dis[i] = dis[u] + 1
					# if i == 99:
					# 	print(u)
					if(m.get(i)):
						# print(i)
						qu.append(m[i])
						if(dis[m[i]] != 0):
							dis[m[i]] = min(dis[m[i]], dis[u] + 1)
						else:
							# dis[i] = dis[u] + 1
							dis[m[i]] = dis[u] + 1
					else :
						# print(i)
						qu.append(i)
			# print('')
	return dis[99]


for _ in range(int(input())):
	l,s = [int(x) for x in input().split(',')]
	la = [x for x in input().split()]
	sa = [x for x in input().split()]
	m = {}
	for i in la:
		j = i.split(',')
		# print(j)
		m[int(j[0]) - 1] = int(j[1]) - 1
	for i in sa:
		j = i.split(',')
		# print(j)
		m[int(j[0]) - 1] = int(j[1]) - 1
		# print(m)
	print(fun(m))