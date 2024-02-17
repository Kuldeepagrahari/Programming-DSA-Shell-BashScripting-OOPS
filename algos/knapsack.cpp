#include <bits/stdc++.h>
using namespace std;

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

int main(){

    int n;
    cin >> n;
    cout << "input truck size: " ;
    int k;
    cin >> k;
   vector<pair<int,int>>v;
   for ( int i = 0; i< n; i++){
       int a,b;
       cin >> a >> b;
       v[i].push_back({b,a});
   }
   pairprint(v);
   int ans = 0;
   int size = k;
   int ind = -1;
   sort ( v.begin(), v.end(), greater<int>() );
   for ( int i = 0;i< n; i++ ){
       
       if ( v[i].second <= size) {
            size -= v[i].second;
             ans += v[i].first * v[i].second;
       }
       else {
          ind = i;
          break;
       }
   }
   if ( ind == -1 ) cout << ans <<endl;
   else{
         ans += size * v[i].first;
         cout << ans <<endl;
   }

}