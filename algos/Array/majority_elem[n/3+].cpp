class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      // moore voting algo
      int n = nums.size();
      int c1 = 0 , c2 = 0;
      int e1 = -1, e2 = -1;

      for ( int i = 0 ; i < n ; i++ ){
        // for ensuring e1  & e2 to be two unique values we are applying the condition of !=
          if ( c1 == 0 && nums[i] != e2 ){
            c1 = 1;
            e1 = nums[i];
          }
          else if ( c2 == 0 && nums[i] != e1 ){
            c2 = 1;
            e2 = nums[i];
          }
          else if ( nums[i] == e1 )c1++;
          else if ( nums[i] == e2 ) c2++;

          else {
            c1--;
            c2--;
          } 
      }

      // checking

      int e1c = 0, e2c = 0;

      for ( int i = 0 ; i  < n ; i ++ ){
        if ( nums[i] == e1 )e1c++;
        else if ( nums[i] == e2 )e2c++;
      }
      vector<int> ans;
      if ( e1c > n/3 ) ans.push_back(e1);
      if ( e2c > n/3 )ans.push_back(e2);
      return ans;
    }  
};