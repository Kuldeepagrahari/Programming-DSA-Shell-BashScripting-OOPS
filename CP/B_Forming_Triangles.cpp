#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
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
int main(){
    int tt;
    cin>>tt;
    while(tt--){
    int n;
    cin>>n;
    int a[n+1];
    int ans=0;
    for(int i=1;i<=n;i++){
         cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n+1;i++){
        if(a[i]==a[i+1]){
            ans+=(i-1);
        }
    }
    cout<<ans<<endl;
}
}