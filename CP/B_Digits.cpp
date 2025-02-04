#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        int d;
        cin >> d;

        vector<int> ans;
        ans.push_back(1);
        int f6 = 0;
        // if(d % 2 == 0 ){ans.push_back(2);f6++;}
       
        if(d% 3 == 0 || n >= 3){ans.push_back(3);f6++;}
        // if(d%4 == 0 )ans.push_back(4);
        if(d == 5)ans.push_back(5);
        // if(f6 == 2)ans.push_back(6);
        if(d == 7 || n >= 3)ans.push_back(7);
        // if(d == 8)ans.push_back(8);
        if(d == 9 || n >= 6)ans.push_back(9);
        for(int i = 0 ; i < ans.size(); i++ )cout << ans[i] << " ";
        cout << endl;



        

    }
}