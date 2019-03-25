n,k = [int(x) for x in input().split()]
a = []
for _ in range(n):
	a.append([int(x) for x in input().split()])
for i in range(k):
	for j in range(n):
		total = sum(a[j])
		kco = a[j][i]
		if j == 0:
			p = kco / total
			# print('0', p)
		else:
			# print(kco, total)
			y = ((kco + 1) / (total + 1)) * p
			# print(p)
			y += (kco / (total + 1)) * (1 - p)
			p = y
			# p = (p * ((kco + 1) / total + 1)) + ((1 - p) * ((kco) / total + 1))
			# print(kco,total)
			# print('n',p)
	print(p, end = ' ')