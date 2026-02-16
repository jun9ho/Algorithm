#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> money) {
    long long answer = 0;
    if(money.size()==3){
        return max(max(money[0],money[1]),money[2]);
    }
    vector<long long> v1(money.begin(),money.end()-1);
    vector<long long> v2(money.begin()+1,money.end());
    vector<long long> dp1(v1.size(),0);
    vector<long long> dp2(v2.size(),0);
    dp1[0] = v1[0];
    dp1[1] = max(v1[0],v1[1]);
    dp2[0] = v2[0];
    dp2[1] = max(v2[0],v2[1]);
    for(int i=2;i<v1.size();i++){
        dp1[i] = max(dp1[i-1],dp1[i-2]+v1[i]);
    }
    for(int i=2;i<v1.size();i++){
        dp2[i] = max(dp2[i-1],dp2[i-2]+v2[i]);
    }
    
    return max(dp1[dp1.size()-1],dp2[dp2.size()-1]);
}