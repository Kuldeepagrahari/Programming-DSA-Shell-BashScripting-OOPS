#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin >> a >> b;
        int aa=a,bb=b;
        int aaa=a,bbb=b;
        int flag=1;
        a*=2;
        b/=2;
      /* The code snippet `aa/=2; bb*=2; if( a!= || aa!=aaa)cout <<"yes\n"; else cout <<"no\n";` is
      performing the following operations: */
        aa/=2;
        bb*=2;
        if( a!= a|| aa!=aaa)cout <<"yes\n";
        else cout <<"no\n";
    
        // if ( (a!=aaa && b==bbb) || (aa==aaa && bb==bbb))
        // if ( a%2==0 ){
        //     if( b%2==0 ){
        //         a*=2;
        //         b/=2;
        //     }
        //     else {
        //         a/=2;
        //         b*=2;
        //     }
        // }
        // else if ( b% 2==0){
        //     if( a%2==0 ){
        //         a/=2;
        //         b*=2;
        //     }
        //     else{
        //         a*=2;
        //         b/=2;
        //     }
        // }
        // else{
        //     flag==0;
        // }

        // if( flag==1 ){
        //     if ( (a==aa && b==bb) || (a==bb && b==aa))cout << "no\n";
        //     else cout <<"yes\n";
        // }
        // else cout << "no\n";
    }
    
}