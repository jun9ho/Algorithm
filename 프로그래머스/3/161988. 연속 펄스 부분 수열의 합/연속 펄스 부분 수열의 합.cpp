#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    vector<long long> dp1(sequence.size(),0); //1 -1
    vector<long long> dp2(sequence.size(),0); //-1 1
    //1. 부분수열의 최대값 구하는 방식을 알아야함
    
    int size = sequence.size();
    dp1[0] = sequence[0];
    dp2[0] = sequence[0] *-1;
    for(int i=1;i<size;i++){
        long long a = sequence[i];
        long long b = sequence[i];
        if(i%2==1) a*=-1;
        else b*=-1;
        dp1[i] = max(a+dp1[i-1],a);
        dp2[i] = max(b+dp2[i-1],b);
    }
    long long maxx1= -1;
    long long maxx2= -1;
    for(int i=0;i<dp1.size();i++){
        maxx1=max(dp1[i],maxx1);
        maxx2=max(dp2[i],maxx2);
    }
    return max(maxx1,maxx2);
}