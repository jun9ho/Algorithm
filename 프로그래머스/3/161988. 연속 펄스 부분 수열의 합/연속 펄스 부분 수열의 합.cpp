#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = LONG_MIN;
    vector<long long> dp1(sequence.size());
    vector<long long> dp2(sequence.size());
    
    dp1[0] = (long long)sequence[0];
    dp1[1] = max(dp1[0]+sequence[1]*-1, (long long)sequence[1]*-1);
    
    dp2[0] = (long long)sequence[0]*-1;
    dp2[1] = max(dp2[0]+(long long)sequence[1], (long long)sequence[1]);
    
    for(int i=2;i<sequence.size();i++){
        if(i%2==0){
            dp1[i] = max(dp1[i-1]+(long long)sequence[i], (long long)sequence[i]);
            dp2[i] = max(dp2[i-1]+(long long)sequence[i]*-1, (long long)sequence[i]*-1);
        }
        else{
            dp1[i] = max(dp1[i-1]+(long long)sequence[i]*-1, (long long)sequence[i]*-1);
            dp2[i] = max(dp2[i-1]+(long long)sequence[i], (long long)sequence[i]);
        }
        
    }
    
    //2 -3 -6 -1 3 1 2 -4
    //2 -1 -6 -1 3 4 6 2
    
    //-2 3 6 1 -3 -1 -2 4
    //-2 3 9 10 7 6 4 8
    for(int i=0;i<sequence.size();i++){
        answer = max(answer,dp1[i]);
        answer = max(answer,dp2[i]);
        
    }
    
    
    return answer;
}