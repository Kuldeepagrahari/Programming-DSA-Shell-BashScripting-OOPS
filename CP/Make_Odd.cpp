#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      string s1, s2;
      cin >> s1 >> s2;

      int i = 0 ; 
      int c = 0, c2 = 0;
      while ( i < n ){
        if ( s1[i] == s2[i] && s1[i] == '1' ){
            c++;
        }else if ( s1[i] != s2[i]) {
            c2++;
        }
        i++;
      }

      if ( c & 1 )cout << "YES\n";
      else {
        if(c2 >=1 )cout << "YES\n";
        else cout << "NO\n";
      }
        

    }
}