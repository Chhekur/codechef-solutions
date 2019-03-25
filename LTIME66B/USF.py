# prime = {1:[1],2:[2]}
# for i in range(1,101):
# 	j = 2
# 	n = i
# 	while(j * j <= i):
# 		if(n % j == 0):
# 			if prime.get(i):prime[i].append(j)
# 			else: prime[i] = [j]
# 			while(n % j == 0): n //= j
# 		j += 1
# 	if(n > 2):
# 		if prime.get(i):prime[i].append(n)
# 		else: prime[i] = [n]
# print(prime)
# print(prime)
def isPrime(n):
	i = 2
	f = 0
	while(i * i <= n ):
		if(n % i == 0): return False
		i += 1
	return True
for _ in range(int(input())):
	n = int(input())
	a = [int(x) for x in input().split()]
	# a.sort()
	dp = {}
	p = set()
	prime = {}
	for i in a:
		if(dp.get(i)):dp[i] += 1
		else: dp[i] = 1
		if isPrime(i):p.add(i)
	# print(dp)
	# print(p)
	p = list(p)
	p.sort()
	for i in dp:
		for j in p:
			if(i % j == 0):
				if prime.get(i):prime[i].append(j)
				else: prime[i] = [j]
	ans = 0
	# print(prime)
	for i in range(len(p)):
		for j in range(i, len(p)):
			count = 0
			# print(prime)
			for l in prime:
				# print(l)
				# print(p[i:j + 1])
				# print(prime[l])
				if all(elem in prime[l]  for elem in p[i:j + 1]): 
					# print(p[i:j + 1], prime[l])
					count += 1
			# print(count)
			# for o in p[i:j + 1]:
			# 	count += dp[o] - 1
					# print(l,dp[l])
					if(dp.get(l)):
						count += dp[l] - 1
			# print(p[i:j + 1], count)
			ans = max(ans, count * len(p[i:j + 1]))
	print(ans)
			# 		e = 0
			# 		for m in p[i:j + 1]:
			# 			if(dp.get(m)):e += 1
			# 		if(e == len())
			# 		count += 1
			# 	# if p[i:j + 1] in prime[l] : count += 1
			# print(count)