#include <bits/stdc++.h>
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
    cin>>t;
    while(t--){
        int n , k;
        cin >> n >> k;
        int v[n];
        for ( int i = 0; i < n; i++  ){
            cin >> v[i];
        }
        
        int dif = 0;
        int diff[n-1];
        for ( int i = 0; i< n-1 ;i++) {
             diff[i] = abs(v[i+1] - v[i]);
        }
        sort ( diff,diff+n );
        int ans = accumulate(diff,diff+n-k,0);
        cout << ans << endl;

        
    }
}