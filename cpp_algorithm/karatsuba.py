'''
Author: huangqianfei
Date: 2022-10-09 14:33:01
Description: 
'''
import math

class karatsuba:

	def _init__(self):
		print("Karatsuba online!")
	
	def to_string(self, x, y):
		sx = str(x)
		sy = str(y)
		nx = len(sx)
		ny = len(sy)
		return sx, sy, nx, ny

	def multiply(self, x, y):
		sx, sy, nx, ny = self.to_string(x, y)

		if nx == 1 or ny == 1:
			r = int(x) * int(y)
			return r
		
		n = nx
		if nx > ny:
			sy = sy.rjust(nx, '0')
			n = nx
		elif ny > nx:
			sx = sx.rjust(ny, '0')
			n = ny
		
		m = n % 2
		offset = 0

		if m != 0:
			n += 1
			offset = 1
		floor = int(math.floor(n / 2)) - offset
		ceil = int(math.ceil(n / 2)) - offset
		a = sx[0:floor]
		b = sx[ceil:n]
		c = sy[0:floor]
		d = sy[ceil:n]

		ac = ((10 ** n) * self.multiply(a, c))
		bd = self.multiply(b, d)
		# (a + b) * (c + d) - ac - bd = ad + bc
		r = ac + ((10 ** (n / 2)) * (self.multiply(a, d) + self.multiply(b, c))) + bd
		return r


k = karatsuba()

print(k.multiply(773920, 583922303))