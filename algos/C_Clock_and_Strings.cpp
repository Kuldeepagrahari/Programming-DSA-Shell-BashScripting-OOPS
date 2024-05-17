#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t--){
      int a,b,c,d;
      cin >> a >> b >> c >> d;

      int maxi1 = max(a,b);
      int mini1 = min ( a,b);

       int maxi2 = max(c,d);
      int mini2 = min ( c,d);

      if ( mini1 < mini2  && mini2 <= maxi1){
         if ( maxi2 >= maxi1)cout << "YES\n";
         else cout << "NO\n";
      }
      else if ( mini1 < mini2  && mini2 > maxi1)cout << "NO\n";
      else if ( mini1 > mini2  && maxi2 >= mini1){
       if ( maxi1 >= maxi2 )cout << "YES\n";
       else cout << "NO\n";

      }
      else cout << "NO\n";

       
    }
}