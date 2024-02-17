#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cin >> n;
    cout << "input truck size: " ;
    int k;
    cin >> k;
    vector< pair<int,int> >vp;
   for ( int i = 0; i< n; i++){
       int a,b;
       cin >> a >> b;
       vp.push_back({b,a});
   }
//    pairprint(v);
   int ans = 0;
   int size = k;
   int ind = -1;
   sort ( vp.begin(), vp.end(), greater<int>() );
   int i =0 ;
   for ( auto & s: vp){
       
       if ( s.second <= size) {
            size -= s.second;
             ans += s.first * s.second;
       }
       else {
        //   ind = i;
          ans += size * s.first;
          break;
       }
       i++;
   }
   cout << ans;

}