#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    int sz = works.size();
    for(int i=0;i<sz;i++){
        pq.push(works[i]);
    }

    for(int i=0;i<n;i++){
        int a = pq.top();
        pq.pop();
        a--;
        if(a<=0) a=0;
        pq.push(a);
    }
    int size=pq.size();
    for(int i=0;i<size;i++){
        answer+= (pq.top()*pq.top());
        pq.pop();
    }
    return answer;
}