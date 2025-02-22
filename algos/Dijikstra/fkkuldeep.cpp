#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 1, 1, 2, 3, 5, 7};
    int  j = 0;
    int c = 0;
    for ( int i = 0; i < 7; i++ ){
        for ( int k = j + 1; k < 7 ; k ++ ){
           if ( v[k] > v[i]){
            j = k +1;
            break;
           }
        }
        cout << j << " " << c;
        if ( v[j] > v[i])c++;
         if ( j == 6 )break;
        
    }
    cout << c;

}