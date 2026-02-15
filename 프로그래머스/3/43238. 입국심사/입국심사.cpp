#include <bits/stdc++.h>

using namespace std;

bool doit(long long mid,vector<int> times,int n){
    long long sum=0;
    for(int i=0;i<times.size();i++){
        sum +=  (mid/times[i]);
    }
    if(sum>=n) return true;
    else return false;
    
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());
    
    long long r = 0;
    long long l = n*times[times.size()-1];
    
    while(r<l){
        long long mid = (r+l)/2;
        
        bool isCan = doit(mid,times,n);
        if(isCan){
            l = mid;
        }
        else{
            r = mid+1;
        }
        if(r==l)
            break;
        
    }
    
    
    answer = r;
    return answer;
}