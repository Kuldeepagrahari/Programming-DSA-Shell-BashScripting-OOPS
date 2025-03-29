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
    int f = 1;
    for (int i = 0; i < n ; i ++){
      if( i > 0 && i < n - 1 && s[i] == '1' && ss[i + 1] == '1' && ss[i - 1] == '1') {
        f = 0;
        break;
      }
      else if (i == 0){
        if(s[i] == '1' && ss[i + 1] == '1'){
            f = 0;
            break;
        }
      }else if(i == n - 1){
        if(s[i] == '1' && ss[i - 1] == '1'){
            f = 0;
            break;
        }
      }
    }
    if(f) cout << "YES\n";
    else cout << "NO\n";
   
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
