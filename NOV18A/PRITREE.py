
def chek(n):
	f = True
	for i in range(2,int(n**0.5) + 1):
		if n % i == 0: f = False
	return f

n = int(input())
v = [int(x) for x in input().split()]
prime_pairs, remain = [],[]
for i in range(n):
	if v[i] != 0:
		for j in range(i + 1, n):
			if v[j] != 0:
				if chek(v[i] + v[j]):
					prime_pairs.append((i,j))
					v[i], v[j] = 0, 0
					break
for i in range(n):
	if v[i] != 0: remain.append(i)
if(len(prime_pairs) > 0 and len(remain) > 0):
	size = len(prime_pairs)
	# print(remain)
	# print(prime_pairs)
	for i in range(size):
		# print('Hello')
		prime_pairs.append((prime_pairs[i][0],remain[0]))
		# print(prime_pairs)
	for i in range(len(remain) - 1):
		prime_pairs.append((remain[i], remain[i + 1]))
	for i in range(len(prime_pairs)):
		print(prime_pairs[i][0] + 1, prime_pairs[i][1] + 1)
		
elif len(remain) == 0:
	# size = len(prime_pairs)
	for i in range(len(prime_pairs) - 1):
		prime_pairs.append((prime_pairs[i][0],prime_pairs[i + 1][0]))
	for i in prime_pairs:
		print(i[0] + 1, i[1] + 1)
else:
	for i in range(n - 1):
		print(i + 1, i + 2)
