#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

#define int long long 
int lcm(int a,int b){
    return (a*1LL*b)/__gcd(a,b);

}
pair<int,int> odd(int n){
    int c=0;
    while(n%2==0){
        n/=2;
        c++;
    }
    return {n,c};

}
signed main()
{  
   int t;
   cin>>t;
   while(t--){
   
   int n;
   cin>>n;
   int v[n];
 
   for(int i=0;i<n;i++)cin>>v[i];

   sort(v,v+n,greater<int>());
   set<int>st;
   int ans=0;
   int val;
   for (int i=0;i<n;i++){
    if(v[i]%2==0){
        if(st.count(odd(v[i]).first)==0){
              
              st.insert(odd(v[i]).first);
              ans+=odd(v[i]).second;
        }

    }
   }
   cout<<ans<<endl;

   }
   }