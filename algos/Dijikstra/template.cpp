#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

int getMinOperations(int n, int m, const vector<int>& change, vector<int>& arr) {
    int operations = 0;

    // Process the change array
    for (int i = 0; i < n; i++) {
        int index = change[i] - 1;  // Convert to 0-based index
        if (index >= 0 && index < m) {
            if (arr[index] > 0) {
                arr[index]--;  // Decrease the value at arr[index]
                operations++;
            }
            if (arr[index] == 0) {
                arr[index] = INT_MIN;  // Mark as "processed"
                operations++;
            }
        }
    }

    // Check if all elements in arr have been processed
    for (int i = 0; i < m; i++) {
        if (arr[i] != INT_MIN) {
            return -1;  // If any element is not processed, return -1
        }
    }

    return operations;
}

int main() {
    int n, m;
    
    // Input the size of the arrays
    cout << "Enter the size of the change array (n): ";
    cin >> n;
    cout << "Enter the size of the arr array (m): ";
    cin >> m;

    vector<int> change(n), arr(m);

    // Input the change array
    cout << "Enter the change array: ";
    for (int i = 0; i < n; i++) {
        cin >> change[i];
    }

    // Input the arr array
    cout << "Enter the arr array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    // Get the minimum operations
    int result = getMinOperations(n, m, change, arr);

    // Output the result
    cout << "Minimum operations: " << result << endl;

    return 0;
}
