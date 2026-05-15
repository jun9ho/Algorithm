#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    //윈도우의 max값들을 모아서 min을 구하자
    if(stones.size()==1){
        return stones[0];
    }
    priority_queue<int,vector<int>,greater<int>> apq;
    priority_queue<int> pq;// 최대큐
    map<int,int> m;
    deque<int>dq;
    
    for(auto stone:stones){
        if(dq.size()<k){
            dq.push_back(stone);
            m[stone]++;
            pq.push(stone);
            continue;
        }
        while(1){
            if(m[pq.top()]<=0)pq.pop();
            else break;
        }
        apq.push(pq.top());
        m[dq[0]]--;
        m[stone]++;
        dq.pop_front();
        dq.push_back(stone);
        pq.push(stone);
    }
    while (!pq.empty() && m[pq.top()] <= 0) {
        pq.pop();
    }
    apq.push(pq.top());
    return apq.top();
}