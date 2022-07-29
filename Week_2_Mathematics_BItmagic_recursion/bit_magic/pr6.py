# Check if any Array pair has bitwise XOR greater than bitwise AND



# Approach: The approach to this problem is to find all the possible pairs and check if any of the pairs has bitwise XOR greater than bitwise AND.

# Time Complexity: O(N2)
# Auxiliary Space: O(1)

# Efficient Approach: The problem can be solved efficiently based on the following idea:

# The idea is built on the observation that:

# Bitwise XOR of two same bits is always 0, i.e. 1⊕1 = 0⊕0 = 0 and XOR of two different bit is 1.
# Bitwise AND of two same bits are same as that bit i.e. 1⊕1 = 1 and 0⊕0 = 0 and AND of different bits is always 0.
# Now from the above observation, it can be said that if the MSB (Most significant bit) of two numbers are at different positions then their bitwise XOR will be greater than bitwise AND because.

# The MSB will be the XOR of two different bits which will result in a set bit and bitwise AND of two different bits will be a 0.
# The MSB of bitwise XOR will be a greater power than the MSB of bitwise AND.
# So to find if such a pair is possible check the conditions only for the minimum and the maximum of the array because they are the extreme values of the array. If they have the MSB in the same positions then all other between them will have the MSB in that position and bitwise XOR will never be greater than the bitwise AND for any pair. In all other cases such a pair is possible.




# The code for the above program can be written as follows:-



# Python code for the above approach

# Function to count number of bit
import sys

def countBit(n):

	Count = 0
	while (n):
		n = n // 2
		Count += 1
	
	return Count

# Function to check
# if a pair is present or not
def checkPair(arr,N):

	Min = sys.maxsize
	Max = -sys.maxsize -1

	# Find Maximum and Minimum element
	# of the array
	for i in range(N):
		Min = min(Min, arr[i])
		Max = max(Max, arr[i])
	

	# Check if max and min element have
	# different count of bits
	# then return 1 else return 0
	if (countBit(Min) != countBit(Max)):
		return True
	else:
		return False

# Driver Code

arr = [ 4, 5, 8, 6 ]
N = len(arr)

# Function call
if (checkPair(arr, N)):
	print("Yes")
else:
	print("No")


