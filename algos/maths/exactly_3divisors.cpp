 bool isPrime(int N)
    {
        //Your code here
        if ( N == 1 )return false;
        if ( N == 2 )return true;
        for ( int i = 2 ; i * i <= N ; i++ ){
            if ( N % i == 0 )return false;
        }
        
        return true;
    }
    int exactly3Divisors(int N)
    {
        //Your code here
        int ans = 0;
        if ( N < 4 )return 0;
        for ( int j = 2; j * j <= N; j++  )
        {
            if( isPrime(j) )ans++;
        }
        
        return ans;
       
        
    }