#include <bits/stdc++.h>
using namespace std;
long solve(int numbers[]){
   
    int n=sizeof(numbers) / sizeof(numbers[0]);
    
	vector<long> dp(n + 1, 0); 
	dp[0] = 1; 

	for (int i = 1; i <= n; i++) { 
	
		int prev = dp[0]; 
		dp[0] = dp[i - 1]; 
		for (int j = 1; j <= i; j++) { 
			
			int temp = dp[j]; 
			dp[j] = prev + dp[j - 1]; 
			prev = temp; 
		} 
	} 

	return dp[0] - 1; 
}

int main() 
{  int a[] = {8, 7, 6, 2};
	cout << solve(a);
	
}
