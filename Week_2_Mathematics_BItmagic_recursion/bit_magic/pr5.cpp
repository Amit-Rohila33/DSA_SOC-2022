// Minimize operations to make X equal to Y by replacing X with its bitwise XOR with N

/*Approach: To solve the problem follow the below observations:

Let V be the XOR of X and Y. Now, we want to get V by performing XOR of as few elements as possible, no more than N,
Decrease the value of K by 1 so that we don’t select N = K for performing XOR.
We observe the following three cases:

if V = 0: Then we need zero operations because V=0 means X⊕Y=0 which implies X is already equal to Y.

if V < K: Then we need only 1 operation because  V < K implies it is always possible to find a number N less than equal to K
which on XOR with X will give Y.

If log2(V) = log2(K): In 1st operation we can change the most significant bit only,
and in 2nd operation we can change all bits less than most significant one.
Hence 2 operations.
Else it is not possible to make X equal to Y by doing XOR. This happens in the case where the largest bit of V is greater than the largest bit of K, which means we cannot create this largest bit by any means. Hence we print -1.*/


// The code for the above question is as follows:-



// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of steps
int equalByXOR(int X, int Y, int K)
{
	// Decreasing K by 1 to avoid
	// selecting N == K for XORing
	K--;

	// Ctr variable to count the number of
	// operations required
	int ctr = 0;

	// V be the XOR of X and Y
	int V = X ^ Y;

	// Cases as discussed above in approach
	// 3 cases if possible
	if (V == 0) {
		ctr = 0;
	}
	else if (V <= K) {
		ctr = 1;
	}
	else if (K != 0 && __lg(V) == __lg(K)) {
		ctr = 2;
	}
	else {

		// If not possible
		ctr = -1;
	}

	// Return the minimum number of operations
	return ctr;
}

// Driver code
int main()
{
	int X = 7, Y = 1, K = 5;

	// Function call
	cout << equalByXOR(X, Y, K);
	return 0;
}
