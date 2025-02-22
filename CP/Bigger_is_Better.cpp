#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
//     if (a.first != b.first)
//         return a.first > b.first;
//     return a.second < b.second;
// }

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
      int n;
      cin >> n;

      string s;
      cin >> s;
      int f = 0;

      for ( int i = 0 ;i  < n; i++ ){
        if ( s[i] < 'z'){s[i] = s[i] + 1; f = 1;}
      }
      if ( f == 0 )cout << "-1\n";
      else
      cout << s << endl;
    }
}
