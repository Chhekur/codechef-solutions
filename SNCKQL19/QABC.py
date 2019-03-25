for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	s = ""
	for i in range(n):
		b[i] -= a[i]
	for i in range(1,n):
		s += str(abs(b[i] - b[i - 1]))
	print("TAK") if (s == s[::-1]) else print("NIE")