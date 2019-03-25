for _ in range(int(input())):
	a = [int(x) for x in input().split()]
	b = a[0] - ((a[0] // 2) + 1)
	# print(m)
	ans = 0
	ans += ((a[1] - b) * (a[1] - b))
	ans += ((a[1] - a[0]) * (a[1] - b))
	ans += ((a[1] - a[0]) * (a[1] - a[0]))
	if a[0] < 3: ans = a[1] * a[1] * a[1]
	print(ans)