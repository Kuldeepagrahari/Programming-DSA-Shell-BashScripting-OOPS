#include <bits/stdc++.h>
using namespace std;

void printer(vector<int>v){
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
     }
     cout<<endl;
}
void arrPrint(int ar[],int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
     }
     cout<<endl;
}
vector<int> sort(vector<int>v){
    int maxi = *max_element(v.begin(),v.end());
    vector<int> v_max(maxi + 1, 0);

    for (int i = 0; i < v.size(); i++)
    {
        v_max[v[i]]++;
    }
    int j = 0;

    for (int i = 0; i <= maxi; i++)
    {
        if (v_max[i] != 0)
        {
            while (v_max[i] != 0)
            {
                v[j++] = i;
                v_max[i]--;
            }
        }
    }
    return v;
}
int main()
{
 
    int ar[9]={-3,-3,-2,-7,4,9,6,7,4};
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<9;i++){
        if(ar[i]<0)neg.push_back(-ar[i]);
        else pos.push_back(ar[i]);
    }
    int j=0;
    neg= sort(neg);
    pos=sort(pos);
  for(int i=neg.size()-1;i>=0;i--){
        ar[j++]=-neg[i];
  }
   for(int i=0;i<pos.size();i++){
        ar[j++]=pos[i];
  }

 arrPrint(ar,9);
}