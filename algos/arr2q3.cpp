#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int mid, int right) {  // tc: O(n)
// sc: O(N)
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1+1];
    int R[n2+1];
    L[n1]=1e9;
    R[n2]=1e9;

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

  
}

void mergeRec(int arr[], int left, int right) {
    // sc: O(n+log(n))
    // tc: O(nlogn)
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeRec(arr, left, mid);
        mergeRec(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void mergeSort(int arr[],int n) {
    // sc:o(n)
    // tc:o(nlog(n))
    for (int i = 1; i <= n - 1; i = 2 *i) {
        for (int left = 0; left < n - 1; left += 2 * i) {
            int mid = min(left + i - 1, n - 1);
            int right = min(left + 2 * i - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}
void print(int arr[],int n){
    // tc: o(n)
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"size:";
    cin>>n;
    int arr[n];
    int x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print(arr,n);
    cout<<"\n";
    //recursive
    mergeRec(arr,0,n-1);   //sc: o(n+log(n)), tc:o(n*logn)
    print(arr,n);
    cout<<"\n";
    // iterative
    mergeSort(arr,n);  // sc:o(n) tc: o(nlogn)
    print(arr,n);
    // mergeSortRecursive(arr,0,n);
}