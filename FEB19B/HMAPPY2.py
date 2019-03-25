from math import gcd
for _ in range(int(input())):
	n,A,B,k = [int(x) for x in input().split()]
	a = n // A
	b = n // B
	l = (A * B) // gcd(A , B)
	r = n // l
	print("Win") if(a + b - 2 * r >= k) else print('Lose')