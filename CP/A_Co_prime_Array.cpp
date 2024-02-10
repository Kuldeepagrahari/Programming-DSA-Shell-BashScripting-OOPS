#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define int long long 

signed main()
{  
//    int t;
//    cin>>t;
//    while(t--){
   
   int n;
   cin>>n;
   vector<int>v;
 
   for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
   }
   int ans=0;
//    cout<<__gcd(758298525 , 319645572 );
   for(int i=0;i<v.size()-1;i++){
    if(__gcd(v[i],v[i+1])!=1){
        
        v.insert(v.begin()+i+1,1);
        ans++;
        i++;
        
    }
    // cout<<i<<" ";
   }
   cout<<ans<<endl;
   for(int i=0;i<v.size();i++)cout<< v[i]<<" ";
   cout<<endl;
//    }
}