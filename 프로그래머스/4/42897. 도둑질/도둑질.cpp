#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    vector<int> dp1(size-1,0);// 0 ~ size-1
    vector<int> dp2(size-1,0);// 1 ~ size
    
    dp1[0] = money[0];
    dp1[1] = max(money[0],money[1]);
    for(int i=2;i<dp1.size();i++){
        dp1[i] = max(money[i]+dp1[i-2],dp1[i-1]);
    }
    
    dp2[0] = money[1];
    dp2[1] = max(money[1],money[2]);
    
    for(int i=2;i<dp2.size();i++){
        dp2[i] = max(money[i+1]+dp2[i-2],dp2[i-1]);
    }
    
    
    return max(dp1[dp1.size()-1],dp2[dp1.size()-1]);
}