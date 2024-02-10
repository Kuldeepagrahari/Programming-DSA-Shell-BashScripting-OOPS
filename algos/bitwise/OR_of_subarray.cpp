// Given an array A of size N where, 1\leq N \leq 10^{5}      . The task is to find the OR of all possible sub-arrays of A and then the OR of all these results.
// C++ program to find OR of all the sub-arrays
#include <bits/stdc++.h>
using namespace std;

// function to return OR of sub-arrays
int OR(int a[], int n)
{
	int ans = a[0];
	for (int i = 1; i < n; ++i) 
		ans |= a[i]; 

	return ans;
}

// Driver program
int main()
{
	int a[] = { 1, 4, 6 };
	int n = sizeof(a) / sizeof(a[0]);

	// print OR of all subarrays
	cout << OR(a, n);

	return 0;
}
