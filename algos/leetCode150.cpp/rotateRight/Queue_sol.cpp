 void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

       queue<int> q;

       for ( int i = n - 1 ; i >= 0 ; i-- ){
            q.push(nums[i]);
       }

       for ( int i = 0 ;  i <  k ; i++ ){
          int fronter = q.front();
          q.pop();
          q.push(fronter);
       }

       for ( int i = 0 ; i < n ; i++ ){
        nums[i] = q.front();
        q.pop();
       }

       reverse (nums.begin(), nums.end());
    }