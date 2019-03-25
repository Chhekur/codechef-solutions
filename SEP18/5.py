from math import gcd

def fun(h,w, photo, col,row):
	temp = []
	for i in range(h):
		temp.append(photo[i * w: (i * w) + w])
	new_photo = ""
	for i in temp:
		temp1 = ""
		for j in i:
			new_photo += j * col;
			temp1 += j * col;
		new_photo += temp1 * (row - 1)
	# print(new_photo)
	return new_photo
	# print(new_photo)
	# print(len(new_photo))
	# print(temp)

def find_similarity(photo1,photo2):
	count = 0
	for i in range(len(photo1)):
		if photo1[i] == photo2[i]:count += 1
	return count

for _ in range(int(input())):
	h1,w1 = [int(x) for x in input().split()]
	photo1 = input()
	h2,w2 = [int(x) for x in input().split()]
	photo2 = input()
	new_photo_row = h1 * h2 // gcd(h1,h2)
	new_photo_col = w1 * w2 // gcd(w1,w2)
	print(new_photo_row, new_photo_col)
	size_of_pixel_in_new_photo_col = new_photo_col // w1
	size_of_pixel_in_new_photo_row = new_photo_row // h1
	new_photo1 = fun(h1,w1,photo1,size_of_pixel_in_new_photo_col, size_of_pixel_in_new_photo_row)
	size_of_pixel_in_new_photo_col = new_photo_col // w2
	size_of_pixel_in_new_photo_row = new_photo_row // h2
	new_photo2 = fun(h2,w2,photo2,size_of_pixel_in_new_photo_col, size_of_pixel_in_new_photo_row)
	print(find_similarity(new_photo1, new_photo2))
	# fun(h2,w2,photo2)
