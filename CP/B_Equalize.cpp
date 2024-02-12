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
        sort(v,v+n);
        vector<int> dif;
        dif.push_back ( v[0] );
        for ( int i= 1; i<n; i++ ){
            if ( v[i]!=v[i-1] )dif.push_back(v[i]);
        }
        int ans = 0;
        for(int i=0; i< dif.size(); i++)
        ans =  max ( ans, upper_bound(dif.begin(),dif.end(),dif[i]+n-1)-dif.begin() - i );
       
        cout << ans <<endl;
    }
}