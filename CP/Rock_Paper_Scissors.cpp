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

        int n , m;
        cin >> n ;

        string s;
        cin >> s;
        
        int l = s.length();
        int f = 0;
        int ans = l;
        int c = 1;
        for ( int i = 0 ; i < n - 1 ; i ++ ){
              if ( s[i] == s[i+1] ){
                c++;
              }
              else {
                ans -= c/2;
                c = 1;
              }
 
        }

        ans -= c/2;

        cout << ans << endl;
        

        


       


 
      
    
 
 
   }
}