 long long sumOfDivisors(int N)
    {
      
        long long ans = 0;
        for ( int i = 1 ; i <= N; i++ ){
           ans += (N / i) * i;
        }
        return ans;
        
        //  6 = 1 2 3 6  = 12
        //  7 = 1 7 = 8 
        //  8 = 1 2 4 8 = 15
        // 1 4  8 15 21 33 41 56 
        
        
    }