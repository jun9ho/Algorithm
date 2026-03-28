#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long maxt = 1000000000000000;
    long long mint = 0;
    while(mint<maxt){
        long long curt = (mint+maxt)/2;
        long long sumn = 0;
        for(int time: times){
            sumn+=(curt/time); 
        }
        if(sumn>=n){
            maxt = curt;
        }
        else{
            mint = curt+1;
        }
    }
    
    
    return mint;
}