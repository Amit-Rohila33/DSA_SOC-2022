# Count of operations to make numbers equal by adding power of 2


# Approach: The problem can be solved based on the following observation:

# Observations:

# Here 2i-1 has one set bit i.e. 01,10,100,1000 and so on . 
# We have to convert these 3 numbers X, Y, and Z into binary numbers and make their least significant bit equal by adding 2i-1 to any one of these three numbers and doing same thing to each bit of the number until the most significant bit becomes equal also count the number of moves simultaneously.
# After performing operation if all bits of these three numbers get equal then print the number of moves else print -1. 


# The code for the above question is as follows:-




# Python code to implement the approach

# Function to check if the bit is set or not
def chk(n, bit):
	return 1 if (n & bit) != 0 else 0

# Function to find the minimum number of moves
def minMove(X, Y, Z, N):
	count = 0
	ans = True
	for i in range(N+1):

		if X == Y and Y == Z:
			break

		# Left shifting of bit
		bit = (1 << i)

		cnt = chk(X, bit) + chk(Y, bit) + chk(Z, bit)

		if cnt == 0 or cnt == 3:
			ans = False
			break

		elif cnt == 1:
			if chk(X, bit) == 1:
				X += bit
			elif chk(Y, bit) == 1:
				Y += bit
			else:
				Z += bit

		else:
			if chk(X, bit) == 0:
				X += bit
			elif chk(Y, bit) == 0:
				Y += bit
			else:
				Z += bit
		count += 1
	return count if ans and X == Y and Y == Z else -1

# Driver Code
if __name__ == '__main__':
	X = 1
	Y = 6
	Z = 7
	N = 30
	# Function call
	print(minMove(X, Y, Z, N))


