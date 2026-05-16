#include <bits/stdc++.h>

using namespace std;


bool match(long long mid, vector<int>times, int n){
    long long cnt = 0;
    for(auto time:times){
        cnt+= mid/time;
    }
    
    if(cnt>=n) return true;// 크다는거야mid가
    else return false;
    
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left =0;
    long long right = times[times.size()-1]*(long long)n;
    while(left<right){
        long long mid = (left+right)/2;
        if(match(mid,times,n)){//mid가 넘커
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    
    return left;
}