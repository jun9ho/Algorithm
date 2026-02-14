#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> v(m+2,vector<long long>(n+2,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            v[i][j]=1;
        }
    }
    for(int i=0;i<puddles.size();i++){
        v[puddles[i][0]][puddles[i][1]] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if((i==1)&&(j==1)) continue;
            if(v[i][j]==0) continue;
            v[i][j] = v[i-1][j] % 1000000007 + v[i][j-1] % 1000000007;
            v[i][j] %= 1000000007;
        }
    }
    
    return v[m][n];
}