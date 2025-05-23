#include<bits/stdc++.h>
using namespace std;
double fastExpo(double a, int b){
    if(b == 0) return 1; 
    double power = fastExpo(a, b / 2);
    if(b & 1) return a * power * power;
    else return power * power;
 }
int main() {
    int n;
    double p;
    cin >> n >> p;
    //p = probability of mood change in 1 unit time
    //n = time
    //output = prob after n unit time that the person will be happy if that is happy in start
    

    double ans = fastExpo(1 - 2 * p, n) + 1;
    ans /= 2;
    cout << setprecision(10) << ans << endl;
}

