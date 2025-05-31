#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Jab koi manushya dhredh sankalp se kisi kaam ko karne ka peeda uthata hai, toh daiviya saktiyon ko uska sath dene swayam hi aana hi padta hai : Kuch bhi asambhav nhi rehta hai parth
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a >= b && (c >= b || c >= d)) || (a < b && d <= a && (c >= d || c >= b))) cout << "Gellyfish\n";
    else cout << "Flower\n";
}
int main(){
     int t;
     cin >> t;
     while(t--) solve();
}