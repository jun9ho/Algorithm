#include <bits/stdc++.h>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(m,vector<int>(n,0));
    vector<vector<int>> block(m,vector<int>(n,0));
    
    for(int i=0;i<puddles.size();i++){
        dp[--puddles[i][0]][--puddles[i][1]] =0;
        block[puddles[i][0]][puddles[i][1]] =1;
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            if(block[i][j]) continue;
            if(i==0) dp[i][j]=dp[i][j-1];
            else if(j==0) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=dp[i-1][j]%1000000007+dp[i][j-1]%1000000007;
                dp[i][j] %=1000000007;    
            }
        }
    }
    
    return dp[m-1][n-1];
}