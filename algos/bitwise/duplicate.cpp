#include<bits/stdc++.h>
using namespace std;

int sol(int arr[], int n){
     for (int i = 0; i < n+2; i++)  
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    } 
  
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n+2; i++) 
    { 
        if ((arr[i] / n) == 2) 
            cout << i << " "; 
    } 
}

vector<int> twoRepeated (int arr[], int n) {//    wrong
        // Your code here
         int xorr = arr[0];  
        for ( int i = 1; i < n + 2 ; i++ ){
            xorr ^= arr[i];
        }
        for ( int i = 1; i <= n ; i++ ){
            xorr ^= i;
        }
        // cout << xorr;
        vector<int> ans; 
        for ( int i = 1; i<= n ; i++ ){
            if ( (xorr ^ i) >= 1 && (xorr ^ i) <= n ){
                ans.push_back(xorr^i);
                // cout << ans.back() << " ";
            }
        }
          int f;
        
        for ( int i = n + 2 -1 ; i >= 0 ; i-- ){
            if ( arr[i] == ans[0] ){
                f = 1;break;
            }
            if ( arr[i] == ans [1] ){
                f = 0;break;
            }
        }
        if ( f == 1) reverse(ans.begin(), ans.end());
        // return ans;
        return ans;
    }
    int main () {
        int arr[] = {9, 1 ,5, 6, 4, 3, 10, 8, 4, 2, 2, 7};
        // vector<int> ans = twoRepeated(arr,10);
        sol ( arr, 10 );
        //  cout << ans[0] << " " <<  ans[1] ;
}