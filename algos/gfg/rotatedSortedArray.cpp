#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int key) {
        int n = arr.size();
        int r = n - 1;
        int l = 0;
        
        while ( r >= l ){
            int mid = l + ( r-  l )/2;
            
            if ( arr[mid] == key )return mid;
            
            else if ( arr[mid] >= arr[l] ){
                if ( key < arr[mid] && key >= arr[l]){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            else{
                 if ( key <= arr[r] && key > arr[mid]){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            
            cout << mid << " ";
        }
        
        return -1;
    }
int main(){
    vector<int> arr = {5,6,7,8,9,10,1,2,3};

    cout << search(arr, 10) << " ";
}