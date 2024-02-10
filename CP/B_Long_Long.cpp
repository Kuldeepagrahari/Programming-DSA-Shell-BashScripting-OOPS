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
        int x=0,y=n-1,neg=0;
        while((v[y]>=0 || v[x]>=0) && y>x){
             if(v[y]>=0)y--;
             if(v[x]>=0)x++;
        }
       for (int i=x;i<=y;i++){
        if(v[i]<=0){
            neg++;
           continue;
        }
        else c++;
       }
       if(neg>0 && c==0) cout<<ans<<" "<<"1\n";
       else cout<<ans<<" "<<min(neg,c+1)<<endl;
    }
}