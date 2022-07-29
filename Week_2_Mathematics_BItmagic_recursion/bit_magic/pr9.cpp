// Find square root of a number using Bit Manipulation

/* Approach: To solve the problem using bitwise operators follow the below idea:

Let’s assume that square root of N is X i.e., N ≥ X2.
Let’s consider binary representation of X = ( bm, bm-1, ….., b2, b1, b0 ) where bi represents the ith bit in binary representation of X. Since, the value of each bits can either be 1 or 0, we can represent
X = ( am + am-1 + . . . + a2 + a1 + a0 ) where ai = 2i or ai = 0.

Consider an approximate solution:
Sj = ( am + am-1 + . . . + aj ) and also let Sj = Sj+1 + 2j.
If Sj2 ≤ X2 ≤ N then jth bit is set and 2j is part of the answer. Otherwise, it is 0. */


/* Based on the above observation in each bit position find the contribution of that bit in the answer and add that value to the final answer. Follow the steps mentioned below to implement the above approach:

Initialize a variable (say result) to store the final answer.
Start iterating from the MSB of N:
If the square of (result + ai) is at most N then that bit has contribution in the result [where ai is 2i].
So add the value ai in result.
After iteration is over, the value stored at result is the required answer. */


// The code for the above program can be written as follows:-


// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find square root
int square_root(int N)
{
	// Find MSB (Most significant Bit) of N
	int msb = (int)(log2(N));

	// (a = 2^msb)
	int a = 1 << msb;
	int result = 0;
	while (a != 0) {

		// Check whether the current value
		// of 'a' can be added or not
		if ((result + a) * (result + a) <= N) {
			result += a;
		}

		// (a = a/2)
		a >>= 1;
	}

	// Return the result
	return result;
}

// Driver Code
int main()
{
	int N = 36;

	// Function call
	cout << square_root(N);
	return 0;
}







