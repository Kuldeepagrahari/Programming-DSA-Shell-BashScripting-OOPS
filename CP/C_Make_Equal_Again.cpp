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
        int t;
        cin>>t;
        while(t--){
        int n;
        cin >> n;
        int v[n];
        // int sum=0;
   
        for ( int i=0;i<n;i++){
           cin>>v[i];
        //    sum+=v[i];
        }
        int i=0,j=n-1;
       int v1=v[0];
       int v2=v[n-1];
      
      while(v[j]==v2 ){
        j--;
        // cout<<j;

      }
       while(v[i]==v1){
        i++;
       }
       i--;
       j++;
// cout<<i<<j<<endl;
       if(v1==v2){
          if(j<=i)cout<<"0\n";
          else{
            cout<<j-i-1<<endl;
          }
       }
       else{
          cout<<min((n-i-1),(j))<<endl;
       }

     
       
       
      
           
}}