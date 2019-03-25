ans = [0,0,0,0,0]

m = 1000000007

def mod_pow(a,b,m):
	if b == 0:return 1
	elif b == 1: return a % m
	temp = mod_pow(a,b // 2, m)
	if b % 2 == 0: return (temp * temp) % m
	else : return (temp * temp * a ) % m

for i in range(5,100001,3):
	ans.append((ans[i - 1] + mod_pow(i,i,m)) % m)
	ans.append(ans[i])
	ans.append(ans[i])
for _ in range(int(input())):
	l,r = [int(x) for x in input().split()]
	print((ans[r] - ans[l - 1]) % m)