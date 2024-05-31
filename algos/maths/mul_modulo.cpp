 const int mod = 1e9+7;
        int multiplicationUnderModulo(long long a,long long b)
    {
        //your code here
        int ans = ((a%mod)*(b%mod))%mod;
        return ans;
    }