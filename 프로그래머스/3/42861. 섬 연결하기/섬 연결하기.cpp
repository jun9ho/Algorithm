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
    vector<bool> vis(n,false);
    vis[0] = true;
    for(int i=0;i<v[0].size();i++){
        pq.push({v[0][i].second,v[0][i].first});
    }
    
    while(!pq.empty()){
        int cd = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(vis[cur]) continue;
        answer+=cd;
        vis[cur]=true;
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nd = v[cur][i].second;
            pq.push({nd,next});
        }
        
        
    }
    
    
    return answer;
}