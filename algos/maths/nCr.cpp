 int nCr ( int n, int r ){
        int maxi = max ( r, n-r );
        int mini = min ( r, n-r );

        long long num = 1;
        for ( int i = n ; i >= 1 + maxi ; i--  ){
            num *= i;
        }

        long long deno = 1;
        for ( int i = 1; i <= mini; i++ ){
            deno *= i;
        }

        return num / deno;
    }