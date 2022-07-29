// Check if even and odd count of elements can be made equal in Array

/* Approach: The idea to solve this problem is as follows:

Find the count of even and odd elements (say expressed as CE and CO respectively).

The number of elements needed to be modified = abs(CE – CO)/2.
An even character needed to be halved i times if its right most bit is at (i+1)th position from the right. And an odd element can be made even by multiplying it by 2 in a single operation.

Use this criteria to find the number of operations required and if it is at most K or not. */

// The code of the above question is as follows:-

// C++ code to implement the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible
// to make even and odd element count same
// using at most K operations
bool findCount(int *arr, int N, int K)
{
    // Edge Case
    if (N & 1)
    {
        return 0;
    }

    // Initialize the variables
    int Res, CE = 0, CO = 0;

    vector<int> v(32, 0);

    // Find the index of rightmost set bit
    // for every array element and increment
    // that index of vector, also find even
    // and odd count
    for (int i = 0; i < N; i++)
    {

        if (arr[i] & 1)
            CO++;

        else
            CE++;

        v[ffs(arr[i]) - 1]++;
    }

    // Condition is already true
    if (CE == CO)
    {
        Res = 0;
    }

    // Count of Even > Count of Odd
    else if (CE > CO)
    {

        int n = (CE - CO) / 2;
        Res = 0;

        // Find minimum operations to make the
        // even and odd count equal
        for (int i = 1; i < v.size(); i++)
        {

            if (n >= v[i])
            {
                Res += v[i] * i;
                n = n - v[i];
            }
            else
            {
                Res += n * i;
                break;
            }
        }
    }

    // Count of Odd > Count of Even
    else
    {
        Res = (CO - CE) / 2;
    }

    return Res <= K;
}

// Driver Code
int main()
{

    int Arr[] = {1, 4, 8, 12};

    int N = sizeof(Arr) / sizeof(Arr[0]);
    int K = 2;

    // Function Call
    if (findCount(Arr, N, K))

        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
