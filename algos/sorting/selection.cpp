#include <bits/stdc++.h>
using namespace std;

int select(int arr[], int i, int n) {
    int mini = i;
   
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[mini]) {
            mini = j;
        }
    }
    return mini;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = select(arr, i, n);
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {1, 3, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // experiment
    // int elem = arr[1];
    // swap(arr[0], elem);
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // failed
}
