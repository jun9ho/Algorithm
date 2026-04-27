#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    //야근 피로도는 [야근을 시작한 시점]에서 남은 일의 작업량을 제곱하여 더한 값
    
    priority_queue<long long> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    for(int i=0;i<n;i++){
        int a = pq.top()-1;
        pq.pop();
        pq.push(a);
    }

    while(!pq.empty()){
        if(pq.top()<0) return 0;
        answer+=(pq.top()*pq.top());
        pq.pop();
    }
    
    return answer;
}