#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
    
      int n,m,a,b,c;
      cin >> a >> b >> c;
      int maxi = max({a,b,c});

      int sum = a + b + c;

      int sum2 = sum - maxi ;


      if ( sum&1 ) cout << "-1\n";
      else 
      cout << min ( sum2, sum/2) << endl;
      
      


        
    }
}
