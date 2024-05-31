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

unordered_map<int, int> primes(long long n)
{ // sieve algo
    vector<int> v(n, 1);
    v[0] = v[1] = 0;
    unordered_map<int, int> primefac;
    for ( int i = 2; i < n; i++ )
    {
        if (v[i] == 1)
        {
            primefac[i] = 1;
            for (int j = 2 * i; j < n; j += i)
            {
                v[j] = 0;
            }
        }
        else
            primefac[i * i] = 0;
    }

    return primefac;
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
  
    }

}