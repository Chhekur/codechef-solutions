from sys import stdin, stdout

M = 1e9 + 7

bc = [[1]]
for i in range(1, 1001):
	bc.append([1])
	for j in range(1,i):
		bc[i].append((bc[i - 1][j] + bc[i - 1][j - 1]) % M)
	bc[i].append(1)
	# bc.append(temp)
# print(bc)

for _ in range(int(input())):
	n = int(stdin.readline())
	a = map(int , stdin.readline().split())
	# print(a)
	f = [0]*2001
	ngf = []
	for i in a:
		# print(i)
		f[i] += 1;
	for i in range(1,len(f)):
		f[i] += f[i - 1]
		if f[i] - f[i - 1] > 1: ngf.append(i)
	# print(f)
	final_res = n
	for i in range(3,n + 1, 2):
		final_res = (final_res + bc[n][i]) % M
	# print(final_res)
	for i in ngf:
		for j in range(f[i] - f[i - 1] - 1):
			for k in range(f[i] - f[i - 1] - 1 - j):
				final_res = (final_res + bc[(n - f[i]) + j + f[i - 1] + k][(n - f[i]) + j]) % M
	print(int(final_res))