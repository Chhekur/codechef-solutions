from math import ceil

def calculate_local_ans(days, mid):
	count,local_ans = 0,0
	for day in days:
		if day[0] < mid: break
		t = ceil(abs(day[0] - mid) / day[2])
		count += t
		local_ans = max(local_ans, day[0] - (day[2] * t))
	return (count,local_ans)

n,m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

days = []
for i in range(n):
	days.append((a[i]*b[i],a[i],b[i]))
days.sort(reverse = True)
l,r,final_ans = 0,days[0][0],999999999999999999
while(l <= r ):
	mid = (l + r) // 2
	local_ans = calculate_local_ans(days, mid)
	if local_ans[0] > m: l = mid + 1
	else: r = mid - 1
	if local_ans[0] <= m:final_ans = min(final_ans,local_ans[1])
print(final_ans)