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
        int andd = v[0];
        int orr = v[0];
        for ( int i = 1 ; i< n ; i++ ){
            andd &= v[i];
            orr |= v[i];
        }
        cout << orr - andd << endl;
         
        
    }
}