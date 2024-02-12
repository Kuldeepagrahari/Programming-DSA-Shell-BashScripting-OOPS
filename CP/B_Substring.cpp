#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main()
{
    string s, t;
    cin >> s >> t;
    int ans= INT_MAX;
     for ( int i = 0 ; i < s.length()-t.length()+1; i++ ){
        int k=i,cnt=0;
        for ( int j= 0 ;j < t.length(); j++ ){
            if ( s[k++] != t[j] ) cnt++;
        }
        ans= min ( cnt , ans );
     }
     cout << ans ;
}
