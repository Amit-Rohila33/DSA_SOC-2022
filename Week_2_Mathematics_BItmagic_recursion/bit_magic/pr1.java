// Check if two Binary Strings can be made equal by doing bitwise XOR of adjacent

/* Approach: The problem can be solved based on the following observation: 

The operations have the following effects:

01 becomes 11
10 becomes 11
00 becomes 00
11 becomes 00
Let’s get the easy cases out of the way:

If S2 = S1, the answer is YES
If S2 is 000…00 (i.e S2 does not have a 1), then we can only perform the operation and it will be the third case shown above, which does not change anything. Therefore, the answer is NO if S2 ≠ S1.
Now, assume S2 ≠ S1 and S2 has a 1. It is possible to convert S2 to S1 if and only if S1 has at least two consecutive same characters. */


// The code solution of the above program is as follows:-


// Java code to implement the approach

import java.io.*;
import java.util.*;

class GFG {

	// Function to check whether S2 can be made equal
	// to S1 after performing given operations
	public static void checkEqual(String S1,
								String S2, int n)
	{
		char[] a = S2.toCharArray();
		char[] b = S1.toCharArray();

		int c_1 = 0;
		int c_2 = 0;
		if (String.valueOf(a).equals(String.valueOf(b))) {
			System.out.println("Yes");
		}
		for (int j = 0; j < n; j++) {
			if (a[j] == '1') {
				c_1++;
			}
			if (b[j] == '1') {
				c_2++;
			}
		}
		if (c_1 == 0 && c_2 > 0) {
			System.out.println("No");
		}
		int c = 0;
		for (int k = 0; k < n - 1; k++) {
			if (b[k] != b[k + 1]) {
				c++;
			}
		}
		if (c == n - 1) {
			System.out.println("No");
		}
		else {
			System.out.println("Yes");
		}
	}

	// Driver code
	public static void main(String[] args)
	{
		String S1 = "00100";
		String S2 = "00011";
		int N = S1.length();

		// Function call
		checkEqual(S1, S2, N);
	}
}

