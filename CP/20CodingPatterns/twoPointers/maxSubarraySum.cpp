#include<bits/stdc++.h>
using namespace std;
// Two pointers -> moving in same direction : O(n), o(1)
int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int mxSum = INT_MIN;
    int sum = 0;
    int j = 0;
    pair<int, int> ptr = {-1, -1};
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > mxSum){
            mxSum = sum;
            ptr = {j, i};
        }
        if(sum < 0) {
            sum = 0;
            j = i + 1;
        }
        
    }
    cout << "Max subarray sum is : " << mxSum << endl;
    cout << "Subarray is : ";
    for(int i = ptr.first; i <= ptr.second; i++){
        cout << arr[i] << " ";
    }
    
}