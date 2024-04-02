#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        unordered_set<int> seen; // Hash set to store encountered elements
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (v[i] == 1) continue;
            if ((3 * v[i]) % (v[i] - 1) == 0) {
                int aa = 3 * v[i] / (v[i] - 1);
                if (seen.count(aa)) {
                    ++ans;
                }
            }
            seen.insert(v[i]);
        }

        cout << ans << endl;
    }
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
const int mod = 1e9+7;
template <typename Container>
void printer(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}
signed main(){
        
        int t;
        cin >> t;
        while ( t-- ){
        int n , k , m;
        cin >> n;
        int v[n];
       for ( int i = 0; i < n ; i++ ){
        cin >> v[i];
       }
        vector<int> aa(n,-1);
        for ( int i = 0; i < n ; i++ ){
            if ( v[i] == 1 )continue;
            if ( (3*v[i])%(v[i]-1) != 0 ) continue;
            else {
                aa[i] = 3*v[i]/(v[i]-1);
            }
        }
        int ans = 0;
        for ( int i = 0 ;i < n ; i++ ){
            // if ( aa[i] != -1 ){
                for ( int j = i+1; j <n; j++ ){
                    if ( v[i] == aa[j] ) ans++;
                // }
            }
        }
        // printer(aa);
cout << ans << endl;

        } 
}
    return 0;
}
