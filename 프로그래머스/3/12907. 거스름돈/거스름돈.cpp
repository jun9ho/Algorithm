#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) 
{
	vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int MOD = 1000000007;
    for (int coin : money) {
        for (int sum = coin; sum <= n; sum++) {
        	dp[sum] += dp[sum - coin];
            dp[sum] %= MOD;
            
        }
    }
    return dp[n];
}