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

        int sum = 0;
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
            sum += abs (v[i]);
          
        }
        sort(v,v+n);
       int pre[n+1];
       pre[0]=0;
       for ( int i = 1 ; i< n+1 ; i++ ){
        pre[i] = v[i-1] + pre[i-1];
       }
       int a=0,b=0;
    
       for ( int i = 1; i<= n;i++ ){
        if (pre[i]%2==0)b++;
        else a++;
       }
    //    for ( int i = 0; i<= n; i++ )cout << pre[i]<<" ";
       if ( a>b)cout << "Alice\n";
       else if ( b>a) cout << "Bob\n";
       else cout << "Draw\n";

       
        




        } 
}