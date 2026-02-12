#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.top()<K){
        if(pq.size()==1) break;
        int a = pq.top();
        pq.pop();
        int b= pq.top();
        pq.pop();
        pq.push(a+2*b);
        answer++;
    }
    if(pq.top()<K) return -1;
    
    return answer;
}