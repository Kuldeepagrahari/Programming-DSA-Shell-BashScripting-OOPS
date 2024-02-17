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
       int t;
       cin >> t;
       while(t--){
        int n,k;
        cin>> n >> k;
        if ( k<= 4*n-4 ){
            if(k&1) cout<<k/2+1<<endl;
            else  cout<<k/2<<endl;
           
            
        }
        else{
            if(k==4*n-3){

                 cout<< 2*n-2+1<<endl;
                }
            else cout<< 2*n-2+2<<endl;
        }

       }
        
}