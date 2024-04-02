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
        for ( int i = 0 ; i< n; i++ ){
            cin >> v[i];
        }
        vector<int> v2 ;
        for ( int i = 0; i < n ;i ++ ){
            if ( i+1 == v[i] ){
                v2.push_back(v2[v2.size()-1]+2);
            }
            else v2.push_back(i+1);
        }
         
        
    }
}