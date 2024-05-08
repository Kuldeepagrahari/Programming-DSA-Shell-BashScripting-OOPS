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

bool cmp(vector<int>v1, vector<int>v2 ){
        return v1[1] < v2[1];
    }
     
signed main(){
    int n ;
     cin >> n;
    vector<int>id={101,102,103,104,105,106};
    vector<int>leaves={4,10,0,8,26,38};
    vector<pair<int,int>>vp;
    for ( int i = 0; i< n ; i++ ){
        vp.push_back({leaves[i],id[i]});
    }
    sort(vp.begin(),vp.end());
    reverse(vp.begin (),vp.end());
    for ( auto it : vp ){
        cout << it.second <<" "<<  it.first << endl;
    }
    //O(nlogn)
}