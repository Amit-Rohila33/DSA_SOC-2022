# Maximize Bitwise XOR of K with two numbers from Array



# Approach: The approach to the problem is to:

# Iterate over all the unique pairs in the array and find the xor value of the triplet and keep track of the maximum.

# Follow the steps mentioned below to implement the above idea:

# Use two nested loops for generating all the unique pairs.
# Find the xor of the each triplets arr[i] ⊕ arr[j] ⊕ K.
# Find the maximum of xor for each pair.
# At the end return the maximum xor value obtained.



# The code for the above question can be written in the following way:-



# Python code to implement the approach

# Function to find the maximum Xor
def maxXor(v, k):

	# Here ans will store the maximum xor
	# value possible of the triplet
	n, ans = len(v), 0

	# We will try for all (n*(n+1))/2 pairs.
	# And maximize the 'ans'.
	for i in range(n):
		for j in range(i, n):
			ans = max(ans, v[i] ^ v[j] ^ k)
	return ans

# Driver Code
N, K = 3, 2
arr = [ 1, 2, 3 ]

# Function call
print(maxXor(arr, K))









