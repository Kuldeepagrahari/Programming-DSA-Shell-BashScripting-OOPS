#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";


void solve() {
    int n;
    cin >> n;
    // vector<int> a(n);
    // for (int &x : a) cin >> x;
    if(n % 3 == 0) cout << "Second\n";
    else cout << "First\n";

   
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
