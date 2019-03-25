a = [int(x) for x in input().split()]
s = input()
m = []
b = []
for _ in range(a[1]):
	m.append([x for x in input().split()])
for _ in range(a[2]):
	b.append([x for x in input().split()])

count = 0
x = a[3]
op = []
# print(m)
for i in m:
	# print(i[0])
	if(len(i[0]) == 1):
		for j in range(len(s)):
			if(s[j] != i[0]):
				if((x - abs(s[j] - i[0])) > 0):
					count += 1
					x -= abs(s[j] - i[0])
					op.append((1, j + 1, i[0]))
print(count)
for i in op:
	print(i[0],i[1],i[2])