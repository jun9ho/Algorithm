#include <bits/stdc++.h>

using namespace std;

bool isBig(long long c, int n, vector<int>times){
    long long sum = 0;
    for(auto time:times){
        sum+=(c/time);
    }
    
    if(sum>=n) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int num = times.size();//심사위원 수
    sort(times.begin(),times.end());
    long long max_time = 1000000000000000;
    long long min_time = 0;
    
    while(min_time<max_time){
        long long c = (max_time+min_time)/2;
        bool big = isBig(c,n,times);
        if(big){
            max_time=c;
        }
        else{
            min_time=c+1;
        }
    }
    
    
    return min_time;
}