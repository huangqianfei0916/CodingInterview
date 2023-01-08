'''
Author: huangqianfei
Date: 2022-10-09 14:33:01
Description: 
'''
import math

class karatsuba:

	def _init__(self):
		print("Karatsuba online!")

	def multiply(self, x, y):
		size_x, size_y = len(x), len(y)
		if size_x == 1 or size_y == 1:
			r = int(x) * int(y)
			return r

		n = max(size_x, size_y)

		x_index = int(size_x / 2) if size_x % 2 == 0 else int(size_y / 2) + 1
		y_index = int(size_y / 2) if size_y % 2 == 0 else int(size_x / 2) + 1

		a = x[0:x_index]
		b = x[x_index:]
		c = y[0:y_index]
		d = y[y_index:]

		# print(a)
		# print(b)
		# print(c)
		# print(d)
		# exit()
		ac = self.multiply(a, c)
		bd = self.multiply(b, d)

		# (a + b) * (c + d) - ac - bd = ad + bc
		a_b = int(a) + int(b)
		c_d = int(c) + int(d)
		ac_bd = self.multiply(str(a_b), str(c_d))
		print(ac)
		print(bd)
		print(ac_bd)
		print(n)
		
		return ac * (10 ** n) + (10 ** (n / 2)) * (ac_bd - ac - bd) + bd  


k = karatsuba()

print(k.multiply("32", "123"))