// Minimum length Subarray starting from each index with maximum OR

// Approach: To solve the problem follow the below idea:

// For each index find all the subarrays starting from that index and find the smallest one with maximum bitwise OR.

// The code solution of the above program is as follows:-




/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {

// This function is for finding the minimum length
// maximum OR subarray, for each index
static List<Integer> solve(int[] arr, int N)
{
	List<Integer> len = new ArrayList<>();

	for (int i = 0; i < N; i++) {
	int mxor = 0, mnlen = 0, OR = 0;
	for (int j = i; j < N; j++) {
		OR = OR | arr[j];

		// Updating maximum value found so far
		if (mxor < OR) {
		mxor = OR;
		mnlen = j - i + 1;
		}
	}
	len.add(mnlen);
	}
	return len;
}

public static void main(String[] args)
{
	int[] arr = { 1, 2, 3, 4, 5 };
	int N = arr.length;

	// Function call
	List<Integer> mnlen = solve(arr, N);

	for (int i = 0; i < N; i++) {
	System.out.print(mnlen.get(i) + " ");
	}
}
}




