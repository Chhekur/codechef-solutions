primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
dp = {}
for i in range(len(primes)):
	for j in range(i + 1, len(primes)):
		dp[primes[i] * primes[j]] = 1
# print(dp)

for _ in range(int(input())):
	n = int(input())
	f = 0
	for i in dp:
		if(n % i == 0 and n // i == 2): f = 1
		temp = n - i
		if(dp.get(temp)):
			# print(temp)
			f = 1
	print('YES') if f == 1 else print('NO')
		
