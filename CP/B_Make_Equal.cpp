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
        int sum=0;
   
        for ( int i=0;i<n;i++){
           cin>>v[i];
           sum+=v[i];
        }
             int val=sum/n;
        int f=1;
        for(int i=0;i<n-1;i++){
            if(v[i]<val){f=0;break;}
            else{
                v[i+1]+=v[i]-val;
            }
        }
        if(f==1)cout<<"yes\n";
        else cout<<"no\n";
           
}}