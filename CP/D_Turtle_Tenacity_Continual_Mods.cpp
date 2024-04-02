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
        int n;
        cin >> n;
        int v[n];
        for ( int i=0;i<n;i++) {
            cin >> v[i];
        }
        int v2[n];
        for ( int i = 0; i < n ;i ++ ){
            v2[i] = v[i];
        }

        sort ( v , v + n );
        sort ( v2,v2+n , greater<int>());
        int f = 0;
        int stmod = v[0],endmod = v2[0];
        for ( int i = 1 ;i < n; i++ ){
            stmod %= v[i];
            endmod %= v2[i];
            

        }
        for ( int i = 0; i <n-1; i++ ){
            if ( v[i] % v[i+1] != 0 )f=1;
        }
        if ( stmod != 0 || endmod != 0 )cout << "yes\n";
        else cout << 
        "no\n";


    }
}