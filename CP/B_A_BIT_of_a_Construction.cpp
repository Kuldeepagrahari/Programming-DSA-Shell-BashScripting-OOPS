#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
    
      int n,m;
      cin >> n >> m;
      int val = 1;
      int cur_sum = 0;
      vector<int> ans;
      int c = 0;
      while ( cur_sum < m ){

          ans.push_back(val);
          c++;
          cur_sum += val;
          val *= 2;
          if ( m-cur_sum == n -c)break;
          else if ( m-cur_sum > n - c) {
            cur_sum -= val/2;
            ans.pop_back();
            break;
          }

      }
      int rest = m - cur_sum;
      int rest_cnt = n - ans.size();

      for ( int i = 0 ; i < rest_cnt-1 ; i ++ ){
          ans.push_back(1);
      }
      ans.push_back(rest-rest_cnt+1);

      for(int i = 0 ; i< n ; i++ )cout << ans[i] << " ";
      cout << endl; 


         
    }
}
                        