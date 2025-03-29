#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";


void solve() {
    int n, m;
    cin >> n;
    // pehli ko sabse choti book, dusre ko sabse badi book dedo padhne ke liye, jab vo padh legi to ye sure h ki pehli ne atleast 1 book padh li hogi to ab dusri ko bhi vo sabse choti book se strart krwa do ab dono ek ek krke kitaabe padhti jaengi: yaani ek cycle me hi saari kitaabe padh lengi dono , ans = sum(time_i); par agar dusri ke kitaab khatam krne se pehle hi pehli ne baaki saari kitaabe padh li to pehli ko wait krna padega to hame utna wait time me add krna padega
    vector<ll> a(n);
    ll time = 0;
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    cout << ans << endl;
    
   
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
