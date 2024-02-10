#include<bits/stdc++.h>
using namespace std;

#define int long long 

// int isprime(long long n)
// { // sieve algo
//     vi v(X, 1);
//     v[0] = v[1] = 0;
//     fl(i, 2, X)
//     {
//         if (v[i] == 1)
//         {
//             for (int j = 2 * i; j < X; j += i)
//             {
//                 v[j] = 0;
//             }
//         }
//     }
//     if (v[n])
//         return 1;
//     else
//         return 0;
// }

signed main()
{   
    int  t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       string s;
       cin >> s;
       vector<int> v;
       int ans=0,ind=-1;
       for ( int i=0;i<n; i++ ){
             if(s[i]=='0') ind=i+1;
       }

       if(ind==-1){
          cout << "0\n";
       }

       else{

       int v[ind+1]={0};
       for (int i=0; i<n; i++){
           if(s[i]=='0') v[i+1]=1;
       }
    //    for (int i=0;i<ind+1;i++ )cout <<v[i];
    //    cout<< endl;
       for ( int i=1;i<= ind; i++ ){
            //   if ( v[i] == -1 || v[i] == 1) {
            // //  cout<<"s";
            // //   ans+=i;
            if(v[i]==1){
              for(int j=i; j<= ind; j+=i ){
                  if(v[j]==1){
                  v[j] = -1;
                  ans+= i;}
                  else{
                    break;
                  }
              }
              }
              if(v[i]==-1){
                 for(int j=2*i; j<= ind; j+=i ){
                  if(v[j]==1){
                  v[j] = -1;
                  ans+= i;}
                  else{
                    break;
                  }
              }
              }
       }
       cout<<ans<<endl;
    }
}}