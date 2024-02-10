#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{   
    int  t;
    cin >> t;
    while(t--){
    int both,a,b,no;
    cin >> both >> a >> b >> no;
    int ans = both;
    int flag =1;
    int ma = both, mb = both;
    // int ans = 0;
    while((a!=0 || b!=0)){
    while(a!=0 ){
        mb--;
        a--;
        ma++;
        ans++;
         if(mb==-1){
            if(b==0){
                break;
                flag=0;
            }
            else{
                ans--;
                mb++;
                a++;
                ma--;
                break;
            }
        }
         
    }
    if(flag==0)break;
  
   
    while(b!=0){
        mb++;
        b--;
        ma--;
        ans++;
        // cout<<"sam"<<ma<<" "<<mb<<endl;
        if(ma==-1){
            if(a==0){
                flag=0;break;
            }
            else{
                ma++;
                mb--;
                b++;
                ans--;
                break;
            }
        }
         
    }
    if(flag==0)break;
    // cout<<ma<<" "<<mb<<endl;

    }
    while((ma!=-1 && mb!=-1 ) && no!=0){
        ma--;
        mb--;
        no--;
        ans++;

    }
    cout << ans <<endl;
}}