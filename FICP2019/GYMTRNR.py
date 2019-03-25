n,k = [int(x) for x in input().split()]
p = []
a = [int(x) for x in input().split()]
for i in range(n):
	p.append([i+1, a[i]])
# print(p)
i = 0
n = len(p)

if (k > sum (a)):print(-1)
else:
	while(k > 0):
		# for i in p:
		if(i < len(p)):
			p[i][1] -= 1
			if(p[i][1] >= 0):
				k -= 1
				if(p[i][1] > 0):
					p.append(p[i])
					# n += 1
			# p.pop(i)
			i += 1
		else :i = 0
		print(p)
	b = []
	for i in p[::-1]:
		if(i[1] == 0):break
		b.append(i)
	print(b)
	if(len(b) == 0):print('perfect')
	else:
		for i in b[::-1]:
			print(i[0], end = ' ')