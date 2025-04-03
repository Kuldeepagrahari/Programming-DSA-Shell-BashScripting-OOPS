#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";


void solve() {
    int n, m;
    string s, ss;
    cin >> n;
    cin >> s >> ss;
    int ones = 0;
    // minimum ceil(n/2) zeros 1st wali alt string me aur min floor(n/2) wali me zeros hone chahiye 
    for(int i = 0; i < n; i++){
      if(i & 1){
        if(s[i] == '1') ones++;
      }else {
        if(ss[i] == '1') ones++;
      }
    }
    if(ones > n -  n / 2) {
      cout << "NO\n";
      return;
    }
    ones = 0;
    for(int i = 0; i < n; i++){
      if(i & 1){
        if(ss[i] == '1') ones++;
      }else {
        if(s[i] == '1') ones++;
      }
    }
     if(ones > n / 2) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
