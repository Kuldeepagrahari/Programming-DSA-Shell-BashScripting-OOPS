#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(vector<int>& arr, int low, int high) {
    stack<int> stack;
    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        int end = stack.top();
        stack.pop();
        int start = stack.top();
        stack.pop();

        int pi = partition(arr, start, end);

        if (pi - 1 > start) {
            stack.push(start);
            stack.push(pi - 1);
        }

        if (pi + 1 < end) {
            stack.push(pi + 1);
            stack.push(end);
        }
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
