from math import ceil, floor

class circle:
	def __init__(self,x,y,r):
		self.x = x
		self.y = y
		self.r = r


def calculate_distance(a,b):
	d = ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y))**0.5
	if d >= a.r + b.r:
		min_distance = ceil(d - a.r - b.r)
		max_distance = floor(d + a.r + b.r)
		return (min_distance, max_distance)
	else:
		min_distance = max(a.r,b.r) - (d + min(a.r,b.r))
		if l < 0: l = 0
		l = ceil(l)
		max_distance = floor(d + a.r + b.r)
		return (min_distance, max_distance)

n,q = [int(x) for x in input().split()]
circle_pairs = []
lower,upper = [0]*1000005,[0]*1000005
ans = [0]*1000005
max_distance = 0
for _ in range(n):
	t = [int(x) for x in input().split()]
	circle_pairs.append(circle(t[0],t[1],t[2]))
	
for i in range(n):
	for j in range(i + 1, n):
		distances = calculate_distance(circle_pairs[i],circle_pairs[j])
		lower[distances[0]] += 1
		upper[distances[1]] += 1
		max_distance = max(max_distance, distances[1])
ans[0] = (lower[0] - upper[0])

for i in range(1,max_distance + 1):
	ans[i] = ans[i - 1] + lower[i] - upper[i - 1]
	
for _ in range(q):
	query = int(input())
	print(ans[query])