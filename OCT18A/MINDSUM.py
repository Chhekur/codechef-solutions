def chek_digit_sum(n):
	if n > 9:
		s = 0
		while(n != 0):
			s += n % 10
			n //= 10
		return s
	return n

for _ in range(int(input())):
	n,d = [int(x) for x in input().split()]
	dp = {}
	calculated_states = [(n,0)]
	final_ans, final_steps = n , 0
	timer = 100000
	while(len(calculated_states) > 0 and timer > 0):
		timer -= 1
		value = calculated_states[0]
		# print(value)
		del calculated_states[0]
		# print(calculated_states)
		if(value[0] < final_ans):
			final_ans = value[0]
			final_steps = value[1]
		solve = chek_digit_sum(value[0])
		# print(solve)
		if not dp.get(solve):
			dp[solve] = 1
			calculated_states.append((solve,value[1] + 1))
			calculated_states.append((value[0] + d,value[1] + 1))
	print(n,0) if(final_ans == n) else print(final_ans,final_steps)