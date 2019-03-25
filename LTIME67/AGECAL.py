for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	c = [int(x) for x in input().split()]
	age = 0
	# print(abs(b[0] - c[0]))
	if abs((b[0] - c[0])) > 1:
		# print('Hello')
		for i in range(b[0] + 1, c[0]):
			# print(i, end = ' ')
			if i % 4 == 0:
				age += 1
			age += sum(a)
	# print(age)
	if(b[0] != c[0]):
		for i in range(b[1] - 1, n):
			if i == b[1] - 1:
				if i == n - 1 and (b[0]) % 4 == 0:
					age += 1
				age += (a[i] - b[2]) + 1
			else:
				if i == n - 1 and (b[0]) % 4 == 0:
					age += 1
				age += a[i]
		for i in range(c[1]):
			if i == c[1] - 1:
				age += c[2]
			else:
				age += a[i]
	elif b[0] == c[0] and b[1] == c[1] and c[2] == b[2]:
		age = 1
	elif b[0] == c[0]:
		# if b[0] % 4 == 0: age += 1
		for i in range(b[1] - 1, c[1]):
			if i == b[1] - 1:
				if i == n - 1 and (b[0]) % 4 == 0 and (b[1] != c[1]):
					age += 1
				if b[1] == c[1]:
					age += abs(b[2] - c[2]) + 1
				else:
					age += (a[i] - b[2]) + 1
			elif i == c[1] - 1:
				age += c[2]
			else:
				age += a[i]
	print(age)