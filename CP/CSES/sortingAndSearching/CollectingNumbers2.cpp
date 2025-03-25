
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n";

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], cerr << v[i] << ' ';
        cerr << '\n';
    vector<int> vis(n, 0);
    map<int, int> ind;

    int rounds = 0;
    for(int i = 0; i < n; i++){
        vis[v[i]] = 1;
        if(vis[v[i] - 1] == 0) rounds++;
        ind[v[i]] = i;
    }

    while(m--){
           cerr << "m -> " << m << '\n';
 
        int l, r;
        cin >> l >> r;
        if(ind[v[r] - 1] < r && ind[v[r] - 1] > l) rounds++;
        if(ind[v[l] + 1] > l && ind[v[l] + 1] < r) rounds++;
        if(ind[v[l] - 1] > l && ind[v[r] + 1] <= r) rounds--;
        
        
        swap(v[l], v[r]);
        cout << rounds << endl; 
    }


    

}
// 4 2 1 5 3
// 2 3


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // Run Stress Test
    // stress_test(1000);

    return 0;
}
