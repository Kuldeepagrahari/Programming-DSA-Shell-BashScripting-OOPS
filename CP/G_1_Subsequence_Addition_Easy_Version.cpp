#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define int long long 
signed main()
{  
   int t;
   cin>>t;
   while(t--){
   
   int n;
   cin>>n;
   int v[n];
   for(int i=0;i<n;i++)cin>>v[i];
   sort(v,v+n);
   int pre=1;
   int flag=1;
   if(v[0]==1){
   for(int i=1;i<n;i++){
       if(v[i]>pre){
          flag=0;
       }
       pre+=v[i];
     
   }
   if(flag==1)cout<<"YES\n";
   else cout<<"NO\n";
   }
   else cout<<"NO\n";
}}