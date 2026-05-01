#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<pair<int,int>>> v(n);
    for(auto cost:costs){
        v[cost[0]].push_back({cost[1],cost[2]});
        v[cost[1]].push_back({cost[0],cost[2]});
    }
    
    vector<bool> vis(n, false);
    //edge cost, node
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0,0});
    long long total = 0;
    int count = 0;
    while(!pq.empty() && count<n){
        int w = pq.top().first; //cost
        int u = pq.top().second; //node;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        total+=w;
        count++;
        for(int i=0;i<v[u].size();i++){
            int nu = v[u][i].first;
            int nw = v[u][i].second;
            if(!vis[nu]) pq.push({nw,nu});
            
        }
    }
    
    return total;
}