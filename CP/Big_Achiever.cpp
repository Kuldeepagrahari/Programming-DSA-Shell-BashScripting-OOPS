#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int>v(n);
      vector<int>ans(n);
      for(int i = 0 ; i < n ; i++ ){
        cin >> v[i];
      }
      int maxi = 0;
      for ( int i= 0 ; i < n ; i ++ ){
         if ( maxi < v[i]){
            ans[i] = 1;
            maxi = v[i];
         }else ans[i] = 0;
      }

      for ( int i : ans)cout << i << " ";
      cout << endl;

        

    }
}