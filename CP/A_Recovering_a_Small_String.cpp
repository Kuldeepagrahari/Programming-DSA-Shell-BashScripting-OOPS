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
        string s;

        if ( n>52 ){
            char x=97+n-53;
            s+=x;
            s+='z';
            s+='z';
        //    s+=(char)(97+25);
           }
           else if (n>27){
            s+='a';
            // n--;
            // int x=n-27;
            char y=97+n-28;
            s+=y;
            s+='z';

            
           }
           else {
            s+='a';
            s+='a';
            s+=(char)(97+n-2-1);
           }
           cout<<s<<endl;
           
}}