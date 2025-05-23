#include<bits/stdc++.h>
using namespace std;

double fastExpo(double a, int b){
   if(b == 0) return 1; 
   double power = fastExpo(a, b / 2);
   if(b & 1) return a * power * power;
   else return power * power;
}
int main() {
   double a = 0.326;
   int b = 2;
   double power = fastExpo(a, b);
   cout << setprecision(6) << power << endl;
   // 3^4 3^4 3
   // 3^2 3^2 3^2 3^2 3
   // 3 3 3 3 3 3 3 3 3

   
}