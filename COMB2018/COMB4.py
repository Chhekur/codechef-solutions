from math import gcd
h,w,x,y = [int(x) for x in input().split()]
g = gcd(x,y)
x //= g
y //= g
a = h // x
b = w // y
ans1x = x * a
ans1y = y * a
ans2x = x * b
ans2y = y * b

ans = []
if(ans1x <= h and ans1y <= w):ans.append(1)
if(ans2x <= h and ans2y <= w):ans.append(2)
if(len(ans) == 0):print(0,0)
elif(len(ans) == 1 and ans[0] == 1):print(ans1x, ans1y)
elif(len(ans) == 1 and ans[0] == 2):print(ans2x, ans2y)
elif(len(ans) == 2):
	if(ans1x * ans1y < ans2x * ans2y):print(ans1x, ans1y)
	else: print(ans2x, ans2y)