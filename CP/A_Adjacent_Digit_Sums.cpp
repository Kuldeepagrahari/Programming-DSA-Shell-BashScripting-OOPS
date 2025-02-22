#include<bits/stdc++.h>
using namespace std;
int digSum(int n){
    int sum = 0;
    while ( n ){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main(){
    int t;
    cin >> t;
    while ( t-- ){
        int n, m;
        cin >> n >> m ;
        string s = "";
        int j = 9;
        while ( n ){
           if ( n % j == 0 ){s += char(j);}
           else j --;
        }
        
        if ( digSum(digSum(n + 1)) == m )cout << "YES\n";
        else cout << "NO\n";
    }
}