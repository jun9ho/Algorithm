#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    if(sticker.size()==1) return sticker[0];
    vector<int> dp1(sticker.size()-1);
    vector<int> dp2(sticker.size()-1);
    
    dp1[0] = sticker[0];
    dp1[1] = max(sticker[0],sticker[1]);
    dp2[0] = sticker[1];
    dp2[1] = max(sticker[1],sticker[2]);
    
    for(int i=2;i<sticker.size()-1;i++){
        dp1[i]= max(dp1[i-1],dp1[i-2]+sticker[i]);
        dp2[i] = max(dp2[i-1],dp2[i-2]+sticker[i+1]);
    }
    
    
    return max(dp1[sticker.size()-2],dp2[sticker.size()-2]);
}