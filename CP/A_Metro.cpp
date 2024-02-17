#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n" 
#define no cout << "NO\n"  
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
void arrayPrint ( int v[], int n ){
    for ( int i = 0;i < n; i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}

signed main()
{
        int n,s;
        cin >> n >> s;
        int v[n];
        int v2[n];
        for ( int  i= 0; i< n;i ++) {
            cin >> v[i];
        }
        for ( int  i= 0; i < n;i ++) {
            cin >> v2[i];
        }
        int f = 0;
        for ( int i = s ; i< n ; i++ ){
            if ( v[i] + v2[i] == 2 )
            {
                f = 1;
                break;
            }
        }
        
        if ( v[0] == 0 )no;
        else if ( v[s-1] + v2[s-1] == 0 )no;
        else {
            if ( v[s-1] == 1)yes;
            else {
            if ( f == 1 && v2[s-1] == 1)yes;
            else no;
            }
        }
        
}