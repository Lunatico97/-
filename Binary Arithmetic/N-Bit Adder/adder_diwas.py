
# ADDER
# DIWAS ADHIKARI (076BEI014)

# LOGIC GATES
def XOR(A, B):
	return int(A)^int(B)

def AND(A, B):
	return int(A)&int(B)

def OR(A, B):
	return int(A)|int(B)

# 1-BIT ADDER
A = input("A: ")
B = input("B: ")
cIn = input("Carry In: ")
s = XOR(XOR(A, B), cIn)
cOut = OR(AND(A, B), AND(XOR(A, B), cIn))
print("Sum: " + str(s)) 
print("Carry Out : " + str(cOut))

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
	for i in range(len(A)-1,-1,-1):
		s = str(sum(A[i], B[i], cIn)) + s
		cOut = carryOut(A[i], B[i], cIn)
		cIn = cOut
	return cOut, s

cIn = 0
A = input("A: ")
B = input("B: ")
A, B = fixBits(A, B)
print("Fixing bits...")
print("A: ", A)
print("B: ", B)
print("Carry Out |       Sum   ")
print("------------------------")
cOut, S = adder(A, B, cIn)
print(cOut, "\t\t", S)
