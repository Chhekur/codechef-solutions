for _ in range(int(input())):
	s = input()
	f,l,r = 0,0,0
	for i in range(len(s) - 1):
		if(s[i] == s[i + 1]):
			f = 1
			l = i
			break
	for i in range(len(s) - 1,0,-1):
		if(s[i] == s[i - 1]):
			# print(i)
			f = 1
			r = i
			break
	if s[0] == s[len(s) - 1]: f = 1
	if f == 0:print('yes')
	elif(len(s) % 2 != 0): print('no')
	else:
		r,g = 0,0
		for i in range(len(s) - 1):
			if(s[i] == s[i + 1] and s[i] == 'R'): r += 1
			if(s[i] == s[i + 1] and s[i] == "G"): g += 1
		if(s[0] == s[len(s) - 1] and s[0] == "R"):
			# print('R')
			r += 1
		if(s[0] == s[len(s) - 1] and s[0] == 'G'):
			# print(s[0],s[len(s) - 1])
			# print('G')
			g += 1
		# print(r,g)
		if(r < 2 and g < 2 ):print('yes')
		else :print('no')
		# # print(l,r)
		# temp1 = s[:l + 1:]
		# temp2 = s[l+1:r:]
		# temp3 = s[r::]
		# print(temp1, temp2, temp3)
		# temp = s[:l + 1:] + temp2[::-1] + s[r::]
		# # print(temp)
		# f1,f2 = 0,0
		# for i in range(len(temp) - 1):
		# 	if(temp[i] == temp[i + 1]): f1 = 1
		# if(temp[0] == temp[len(temp) - 1]):f1 = 1
		# temp = temp3[::-1] + temp2 + temp1[::-1]
		# # print(temp)
		# for i in range(len(temp) - 1):
		# 	if(temp[i] == temp[i + 1]): f2 = 1
		# if(temp[0] == temp[len(temp) - 1]):f2 = 1
		# print('yes') if f1 == 0 or f2 == 0 else print('no')