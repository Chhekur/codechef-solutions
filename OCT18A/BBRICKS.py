
mod = 1000000007

def modular_inverse(value):
    return fast_mod_pow(value, mod - 2)

def fast_mod_pow(a, x):
    value = 1
    while(x > 0):
        if( x % 2 != 0):
            value = (value * a) % mod
        a = (a * a) % mod
        x //= 2
    return value

def modular_biomial_coffiecient(n, r):

	deno = 1
	for i in range(1, r + 1):
		deno = (deno * i) % mod

	nume = 1
	for i in range(r):
		nume = (nume * (n - i) ) % mod
		print(nume)
	print()

	return ( nume * modular_inverse(deno) ) % mod

for _ in range(int(input())):
	n,k = [int(x) for x in input().split()]
	ans = 0
	if(k > n):print(0)
	else:
		for i in range(k):
			# print(modular_biomial_coffiecient(k - 1,i))
			# print(modular_biomial_coffiecient(n + 1 + i - k, k))
			ans = (ans + 2 *modular_biomial_coffiecient(k - 1, i) * modular_biomial_coffiecient(n + 1 + i - k, k)) % mod
		# print(chek[n][k])
		print(ans)