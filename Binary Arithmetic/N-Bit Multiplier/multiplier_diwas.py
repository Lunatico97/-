
# MULTIPLIER
# DIWAS ADHIKARI (076BEI014)

# LOGIC GATES
def XOR(A, B):
	return int(A)^int(B)

def AND(A, B):
	return int(A)&int(B)

def OR(A, B):
	return int(A)|int(B)

# N-BIT ADDER
def sum(A, B, cIn):
	return XOR(XOR(A, B), cIn)

def carryOut(A, B, cIn):
	return OR(AND(A, B), AND(XOR(A, B), cIn))

def bitShiftRightFor(A, length):
	A = A.rjust(length, '0')
	return A

def bitShiftLeftFor(A, length):
	A = A.ljust(length, '0')
	return A

def fixBits(A, B):
	if(len(A) > len(B)):
		B = B.rjust(len(A), '0')
	elif(len(A) < len(B)):
		A = A.rjust(len(B), '0')
	return A, B

def adder(A, B, cIn):
	s = ""
	cOut = 0
	A, B = fixBits(A, B)
	for i in range(len(A)-1,-1,-1):
		s = str(sum(A[i], B[i], cIn)) + s
		cOut = carryOut(A[i], B[i], cIn)
		cIn = cOut
	s = str(cOut) + s
	return s

# N-BIT MULTIPLIER
def multiplier(A, B):
	A, B = fixBits(A, B)
	im = ""
	r = ""
	shift = 0

	for i in range(len(B)-1, -1, -1):
		for j in range(len(A)-1, -1, -1):
			im =  str(AND(B[i], A[j])) + im 
		im = bitShiftLeftFor(im, len(B)+shift)
		shift += 1
		r = adder(im, r, 0)
		im = ""

	return r

A = input("A: ")
B = input("B: ")
R = multiplier(A, B)
print("Product: ", R) ;

