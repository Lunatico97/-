# SUBTRACTOR
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
	return cOut, s

# COMPLEMENTORS
def NOT(A):
	if(A == '0'):
		return 1 
	else:
		return 0	

def complementor(A):
	AC = ""
	for i in range(len(A)):
		AC = AC + str(NOT(A[i]))
	return AC

def complementor2(A):
	A = complementor(A)
	unity = "1" 
	c, s = adder(A, unity, 0)
	return s

# N-BIT SUBTRACTOR
def subtractor(A, B, bIn):
	B = complementor2(B)
	b, d = adder(A, B, bIn)
	return d

A = input("A: ")
B = input("B: ")
print("Difference: ", subtractor(A, B, 0))

