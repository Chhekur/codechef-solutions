def cal(s, d):
	m = min(s)
	t = ''
	i = s.index(m)
	if(m < d):
		t += m + d * i
		s = s[i + 1::]
	else:
		s = []
	return s, t
	# print(i)
	# print(min(s))

for _ in range(int(input())):
	n,d = [x for x in input().split()]
	s = list(n)
	# print(s)
	ans = []
	ans_final = ''
	while(len(s) > 0):
		# print(s)
		s, t = cal(s, d)
		ans.append(t)
		# print(s,t)
		# ans += t
	# print(ans)
	c = 0
	for i in ans:
		if(len(i) > 0):
			c += 1
			ans_final += i[0]
		# if(len(i) > 1):
		# 	c += 1
		# 	ans_final += i[:len(i) - 1:]
		# else:ans_final += i
	ans_final += d * (len(n) - c)
	print(ans_final)