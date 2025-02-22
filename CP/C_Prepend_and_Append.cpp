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
       int n;
       cin >> n;
       string s;
       cin >> s;
       int st = 0, end = n - 1;

       while ( st < end &&  s[st] != s[end]){
        st++;
        end--;
       }
       cout <<  end - st + 1 << endl;
    }
}