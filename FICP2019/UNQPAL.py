
def subseq(s):
  l = len(s)
  sub = []
  for i in range(len(s)):
    for j in range(i,len(s)):
      sub.append(s[i:j + 1]) 
  return sub

for _ in range(int(input())):
	s = input()
	x = int(input())
	sub = subseq(s)
	ans = 0
	frq = {}
	for i in sub:
		if len(i) == x or len(i) == (len(s) - x):
			# print(i,n)
			if(i == i[::-1]):
				if(not frq.get(i)):
					# print(i)
					ans += 1
					frq[i] = 1
	print(ans)