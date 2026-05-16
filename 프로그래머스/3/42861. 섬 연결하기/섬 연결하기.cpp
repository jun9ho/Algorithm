#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> v(n);
    for(auto cost: costs){
        v[cost[0]].push_back({cost[1],cost[2]});
        v[cost[1]].push_back({cost[0],cost[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> dist(n,false);
    dist[0] = true;
    for(int i=0;i<v[0].size();i++){
        pq.push({v[0][i].second,v[0][i].first});
    }
    
    while(!pq.empty()){
        int curd = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur]) continue;
        dist[cur] = true;
        answer+=curd;
        
        for(int i=0;i<v[cur].size();i++){
            pq.push({v[cur][i].second,v[cur][i].first});
        }
        
    }
    
    
    return answer;
}