from math import ceil


def chek(number_of_coin,k_balance):
	if k_balance == 0: print('{0:.6f}'.format(1 / number_of_coin))
	elif number_of_coin == 1: print('{0:.6f}'.format(1))
	elif number_of_coin == 2: print('{0:.6f}'.format(1 / 2))
	else:
		if(k_balance > 0 and number_of_coin % 2 == 0 and int(number_of_coin / 2) % 2 != 0):
			number_of_coin = ceil(number_of_coin / 2) + 1
			k_balance -= 1
		while(k_balance > 0 and number_of_coin > 1):
			number_of_coin = ceil(number_of_coin / 2)
			k_balance -= 1
		if(k_balance == 0):print('{0:.6f}'.format(1 / number_of_coin))
		elif(number_of_coin == 1):print('{0:.6f}'.format(1))

for _ in range(int(input())):
	number_of_coin,k_balance = [int(x) for x in input().split()]
	chek(number_of_coin,k_balance)