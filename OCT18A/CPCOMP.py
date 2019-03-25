visited = {}

gcds = [0]

def gcd(a, b):
    if a == 0:return b
    return gcd(b % a, a)

def bfs(graph, source):
	q = [source]
	visited[source] = 1
	while(len(q) > 0):
		v = q[0]
		del q[0]
		if graph.get(v):
			for i in graph[v]:
				if not visited.get(i):
					visited[i] = 1
					q.append(i)


n = int(input())
a = list(map(int, input().split()))
c = []
for i in range(n):
	c.append([a[i],i])
# print(c)
c.sort()
g = {}
for i in range(n):
	if c[i][0] == 0: continue
	f = False
	for j in range(i + 1, n):
		if c[j][0] == 0: continue
		if gcd(c[i][0],c[j][0]) == 1:
			f = True
			if(g.get(c[i][1])):g[c[i][1]].append(c[j][1])
			else:g[c[i][1]] = [c[j][1]]
			if(g.get(c[j][1])):g[c[j][1]].append(c[i][1])
			else:g[c[j][1]] = [c[i][1]]
	if not f:
		for k in range(i + 1,n):
			if c[k][0] % c[i][0] == 0 : c[k][0] = 0
count = 0
for i in range(n):
	if not visited.get(i):
		count += 1
		bfs(g,i)
print(count)
# print(a)