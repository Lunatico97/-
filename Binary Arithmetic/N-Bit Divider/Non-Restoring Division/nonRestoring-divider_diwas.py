# DIVIDER (NON-RESTORING METHOD)
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

def bitShiftRightFor(A, length):
        A = A.rjust(length, '0')
        return A

def bitShiftLeftFor(A, length):
        A = A.ljust(length, '0')
        return A

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
	A, B = fixBits(A, B) # Fixing bits earlier for correct complementing
	B = complementor2(B)
	b, d = adder(A, B, bIn)
	return d

# N-BIT DIVIDER
def divider(A, B):
	AC = ""
	A, B = fixBits(A, B)
	AC = bitShiftRightFor(AC, len(A)+1)
	Q = A			

	for i in range(len(A)):
		AC = AC[1:len(AC)] + Q[0]
		Q = Q[1:len(Q)]
		if(AC[0] == '1'):
			f, AC = adder(AC, B, 0)
		else:
			AC = subtractor(AC, B, 0)
		if(AC[0] == '1'):
			Q = Q + '0'
		else:
			Q = Q + '1'	
	# Restore only once
	f, AC = adder(AC, B, 0)
	return Q, AC

A = input("A: ")
B = input("B: ")
print("(Quotient, Remainder)", divider(A, B))

