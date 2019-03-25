for _ in range(int(input())):
	n,p = [x for x in input().split()]
	n = int(n)
	n1,n0 = 0,0
	for _ in range(n):
		a = input()
		# print(a)
		z = a[0]
		if(z == '1'): n1 += 1
		else: n0 += 1
		for i in a:
			# print(i,z)
			if i != z:
				z = i
				if(z == '1'): n1 += 1
				else: n0 += 1
	# print(n1,n0)
	if(p == "Dee"):
		if(n1 == n0):print("Dee")
		elif(n1 < n0):print("Dum")
		else:print("Dee")
	elif(p == "Dum"):
		if(n1 == n0):print("Dum")
		elif(n1 < n0):print("Dee")
		else:print("Dum")