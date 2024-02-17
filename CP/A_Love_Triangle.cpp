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
void arrayPrint ( int v[], int n ){
    for ( int i = 0;i < n; i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}

signed main()
{
        int n;
        cin>>n;
        int v[n+1];
         set<int>st;
        for ( int i = 1 ;i<= n ; i++ ){
            cin >> v[i]; 
            st.insert(v[i]);
        }
        bool f = false;
        for ( int i = 1;i <= n; i++ ){
            if ( v[v[v[i]]] == i ){
                f=true;
                break;
            }
        }
        if( f )cout << "YES\n";
        else cout << "NO\n";
       
}