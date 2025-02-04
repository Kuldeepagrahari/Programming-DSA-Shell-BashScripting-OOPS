#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
      int n, x, k;
      cin >> n >> x >> k;
      string s;
      cin >> s;


      int ans = 2;

      long long ic = 0;
      int c0 = 0;
      for(int i = n- 1; i >= 0; i-- ){
          if ( s[i] == '0'){
            c0++;
          }
          else{
            ic += c0;
          }
      }

      if ( ic <= x && (ic % k == 0))ans = 1;
      cout << ans << endl;


     
        

    }
}