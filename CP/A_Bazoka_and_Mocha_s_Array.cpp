#include<bits/stdc++.h>
using namespace std;
#define int long long
 
template <typename Container>
void printer(const Container &container)
{
    
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{
    
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}


// ------------------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

       int n , m ; 
       cin >> n;

       vector<int > v(n);
    for (int i = 0 ; i < n ;  i ++ )cin >> v[i];
    
    vector<int> v2 = v;
    sort ( v2.begin(), v2.end());

    int c  = 0;
    if(v2 == v )cout << "YES\n";
    else {
           for ( int i = 0 ; i <  n-1 ; i++ ){
        if ( v[i] <= v[i+1] )continue;
        else c++;
    
    }

    if ( c > 1)cout << "NO\n";
    else {
        if ( v[n-1]  <= v[0] )cout << "YES\n";
        else cout <<
        "NO\n";
    }
  }

       
    }

}