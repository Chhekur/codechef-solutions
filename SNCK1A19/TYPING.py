key = {'f':'l', 'd': 'l','j':'r', 'k':'r'}
words = {}
for _ in range(int(input())):
	n = int(input())
	for _ in range(n):
		s = input()
		if words.get(s): words[s] += 1
		else : words[s] = 1
	# print(words)
	final_ans = 0
	for i in words:
		c_word_ans = 0.2
		pre = key[i[0]]
		for j in i[1::]:
			if(key[j] == pre):c_word_ans += 0.4
			else: c_word_ans += 0.2
			pre = key[j]
		final_ans += c_word_ans + ((words[i] - 1) * c_word_ans / 2)
	print(int(final_ans * 10))