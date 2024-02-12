#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{   
    int  t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       int v[n];
       int ans=0;
       int c =0;
       for (int i=0;i<n;i++){
        cin >> v[i];
        ans+=abs(v[i]);
        }
        bool last_pos = true;
        for ( int i=0;i<n;i++ ){
            if(v[i] < 0 && last_pos){
                c++;
                last_pos=false;
            }
            if( v[i]>0 ){
                last_pos=true;
            }
        }
        cout << ans << " " << c<<endl;
    }
}