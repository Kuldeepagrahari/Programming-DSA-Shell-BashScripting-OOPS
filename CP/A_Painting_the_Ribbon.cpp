#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        double x = (double)n/(double)m;
        
        int min_req = n - ceil(x);
        // cout << min_req<<ceil(x);
        if(k >= min_req){
            cout << "NO\n";
            
        }
        else cout << "YES\n";
    }
}