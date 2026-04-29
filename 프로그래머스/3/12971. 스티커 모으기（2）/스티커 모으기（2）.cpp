#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    if(sticker.size()==1) return sticker[0];
    
    vector<int> v1(sticker.begin(),sticker.end()-1);
    vector<int> v2(sticker.begin()+1,sticker.end());
    
    vector<int> dp1(v1.size(),0);
    vector<int> dp2(v2.size(),0);
    
    dp1[0] = v1[0];
    dp1[1] = max(v1[0],v1[1]);
    
    dp2[0] = v2[0];
    dp2[1] = max(v2[0],v2[1]);
    
    int sz = v1.size();
    for(int i=2;i<sz;i++){
        dp1[i] = max(dp1[i-1],dp1[i-2]+v1[i]);
        dp2[i] = max(dp2[i-1],dp2[i-2]+v2[i]);
    }
    
    return max(dp1[dp1.size()-1],dp2[dp2.size()-1]);
}