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

        int n;
 
        cin >> n;
        int l1, l2 , l3 ;
        vector<int> ss;
        vector<int> s;
        int num = n;
        while ( num-- ){
            int l;
            cin >> l;
            vector<int> v(l);
            for ( int i = 0 ; i< l ; i ++ ){
                cin >> v[i];
            }
            sort ( v.begin(), v.end());
            ss.push_back(v[1]);
            s.push_back(v[0]);

            
        }
         int ans = 0;
         sort ( ss.begin(), ss.end());
         sort ( s.begin(), s.end());

        //  printer(ss);
        //  printer(s);
        for ( int  i = 1; i < n ; i++ ){
            ans += ss[i];
            // cout<<n<<endl;
        }
         ans += s[0];

         cout << ans << endl;

       
    }
}
            