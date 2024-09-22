# SIGNED MULTIPLIER (BOOTH'S ALGORITHM)
# DIWAS ADHIKARI (076BEI014)
# Don't forget to read comments for insights !

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

# N-BIT SIGNED MULTPLIER
def signedMultiplier(A, B):
	AC = "" # Accumulator
	# The bit fixes below might seem absurd but, these are vital :)
	A, B = fixBits(A, B)
	junk = '0' # LSB that keeps on getting shifted to the right
	AC = bitShiftRightFor(AC, len(A))
	Q = A

	for i in range(len(A)):
		ludo = Q[-1] + junk
		if(ludo == '01'):
			f, AC = adder(AC, B, 0)
		elif(ludo == '10'):
			AC = subtractor(AC, B, 0)
		print (AC, Q, junk)	
		# Arithmetic Shift Right (ASR)	
		junk = Q[-1]
		Q = AC[-1] + Q[0:len(Q)-1]
		AC = AC[0] + AC[0:len(AC)-1]
		print (AC, Q, junk)	

	# At this point, Booth's Algorithm is already over !
	# From below, I performed some modifications on it for better results !
	if(junk == '1' and AC[0] != '0'):
	# Forcing to complement if sign bit is 1 and the output is not unsigned
		return complementor2(AC + Q), junk
	else: 
	# Forcing sign bit to be 0 in case, both signed digits operate
	# to yield a sign bit of 1 as per Booth's Algorithm
		junk = '0' 
		return AC + Q, junk

A = input("A: ")
B = input("B: ")
print("Product: ", signedMultiplier(A, B))

