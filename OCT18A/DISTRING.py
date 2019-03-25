# co = []
def cal_distinct_row(cordinates):
	dp = {}
	u,d,l,r = cordinates
	s = []
	for row in matrix[u:d+1]:
		t = ""
		for i in range(l,r+1):
			t += str(row[i])
			# print(row[i],end = '')
		# print()
		s.append(t)
	# print(s)
	for i in s:
		if not dp.get(i):dp[i] = 1
	# print(len(dp))
	return len(dp)
		# print(str(row[l:r+1]))
def cal_sub_matrix():
	# co = []
	count = 0
	rows = len(matrix)
	cols = len(matrix[0])
	for u in range(rows):
		for d in range(u, rows):
			for l in range(cols):
				for r in range(l, cols):
					count += cal_distinct_row((u,d,l,r))
					# co.append((u,d,l,r))
	return count

# print(count)

n,m = [int(x) for x in input().split()]
matrix = []
for _ in range(n):
	matrix.append([int(x) for x in input().split()])
print(cal_sub_matrix())
# print(mat)