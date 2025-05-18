#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll ans = 1;
    ll limit = pow(10, k) - 1;
    if(k == 18) limit = 999999999999999999;
    // for(int i = 0; i < k; i++) limit = 10 * limit + 9;

    // ll power = pow(10, 17);
    // cout << power << endl;
    for(int i = 0; i < n; i++){
        if(ans * v[i] > limit) {
            ans = 1;
        }else ans *= v[i];
    }
    cout << ans << endl;
    
}
