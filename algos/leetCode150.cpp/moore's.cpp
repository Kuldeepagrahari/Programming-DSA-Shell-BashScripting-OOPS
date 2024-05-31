 int majorityElement(vector<int>& nums) {
      // moore's voting algo

      int pos_ans = -1;
      int cnt = 0;
      int  i = 0 ;
      int  n = nums.size();

      while (i < n ){

        if ( cnt == 0 ){
             pos_ans = nums[i];
             cnt = 1;
        }
        else if ( pos_ans != nums[i] ){
             cnt--;
        }
        else {
            cnt ++;
        }
        i++;

      }

      return pos_ans;
     O(N), O(1)
        
    }