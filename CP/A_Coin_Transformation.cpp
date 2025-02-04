#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int i = 2;
        if(n <= 3)cout << "1\n";
        else {
        long long ans = 0;
        // n /= 4;
        while(n > 3){
              if(n <= 3 )break;
           ans = i;
           i *=2;
           n /= 4;
         
        }
        cout << ans << endl;
        }


        

    }
}