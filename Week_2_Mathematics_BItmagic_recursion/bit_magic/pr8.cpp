// Find all Unique Subsets of a given Set



/* Approach 1 (Recursion):

Follow the given steps to solve the problem using the above approach:

Iterate over the elements one by one.
For each element, just pick the element and move ahead recursively and add the subset to the result.
Then using backtracking, remove the element and continue finding the subsets and adding them to the result. */


// The code of the above problem can be written as follows:- 



// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Helper function to find all unique subsets
void findSubsets(vector<int>& v, int idx,
				vector<int>& subset,
				set<vector<int> >& result)
{
	// If the current subset is not empty
	// insert it into the result
	if (!subset.empty())
		result.insert(subset);

	// Iterate over every element in the array
	for (int j = idx; j < v.size(); j++) {

		// Pick the element and move ahead
		subset.push_back(v[j]);
		findSubsets(v, j + 1, subset, result);

		// Backtrack to drop the element
		subset.pop_back();
	}
}

// Function to return all unique subsets
vector<vector<int> > solve(vector<int>& v)
{
	// To store the resulting subsets
	set<vector<int> > result;
	vector<int> subset;

	// Helper function call
	findSubsets(v, 0, subset, result);

	vector<vector<int> > res;
	for (auto v : result)
		res.push_back(v);

	return res;
}

// Driver code
int main()
{
	vector<int> A = { 1, 2, 2 };

	// Function call
	vector<vector<int> > result = solve(A);

	// Print all unique subsets
	for (auto v : result) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
