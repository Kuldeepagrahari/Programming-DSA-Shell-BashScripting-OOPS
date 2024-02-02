// C++ program for implement deletion in Heaps

#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index of arr[] and n is the size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
void buildHeap(vector<int>&nums)
{
    // Index of last non-leaf node
    int startIdx = (nums.size() / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(nums,nums.size(), i);
    }
}

// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
	// Get the last element
	int lastElement = arr[n - 1];

	// Replace root with last element
	arr[0] = lastElement;

	// Decrease size of heap by 1
	n = n - 1;

	// heapify the root node
	heapify(arr, n, 0);
}
void insertNode(int arr[], int& n, int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;
 
    // Insert the element at end of Heap
    arr[n - 1] = Key;
 
    // Heapify the new node following a
    // Bottom-up approach
    heapify(arr, n, n - 1);
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver Code
int main()
{
	// Array representation of Max-Heap
	//	 10
	// / \
	// 5 3
	// / \
	// 2 4
	int arr[] = { 10, 5, 3, 2, 4 };

	int n = sizeof(arr) / sizeof(arr[0]);

	deleteRoot(arr, n);

	printArray(arr, n);

	return 0;
}
