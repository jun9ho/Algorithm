#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> v(n);
    vector<bool> vis(n,false);
    
    for(auto cost:costs){
        v[cost[0]].push_back({cost[1],cost[2]});
        v[cost[1]].push_back({cost[0],cost[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0;i<v[0].size();i++){
        pq.push({v[0][i].second,v[0][i].first});
    }
    vis[0]=true;
    while(!pq.empty()){
        int cur  = pq.top().second;
        int curd = pq.top().first;
        pq.pop();
        if(vis[cur]) continue;
        answer+=curd;
        vis[cur]=true;
        for(int i=0;i<v[cur].size();i++){
            pq.push({v[cur][i].second,v[cur][i].first});
        }
    }
    
    return answer;
}