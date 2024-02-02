#include <bits/stdc++.h>
using namespace std;

void algo1(int a[], int start, int end) {
    int size = end - start + 1;

    if (size <= 2) {
        if (size == 2 && a[start] > a[end]) {
            swap(a[start], a[end]);
        }
        return;
    } else {
        int m = ceil(2.0 * size / 3);
        algo1(a, start, start + m - 1); 
        algo1(a, end - m + 1, end); 
        algo1(a, start, start + m - 1); 
    }
}

void algo2(int a[], int start, int end) {
    int size = end - start + 1;

    if (size <= 2) {
        if (size == 2 && a[start] > a[end]) {
            swap(a[start], a[end]);
        }
        return;
    } else {
        int m = floor(2.0 * size / 3);
        algo2(a, start, start + m - 1); 
        algo2(a, end - m + 1, end); 
        algo2(a, start, start + m - 1); 
    }
}


int main() {
    int arr[] = {4, 3, 2, 1, 5, 6, 7, 8,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    algo1(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // --- floor-----------
 algo2(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
