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