#include <bits/stdc++.h>

using namespace std;


vector<int> bfs(vector<vector<int>> v, int source, int n){
    
    
    queue<pair<int,int>> q;
    vector<int> dist(n,INT_MAX);
    q.push({source,0});
    dist[source]=0;
    while(!q.empty()){
        int cur = q.front().first;
        int curd = q.front().second;
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            int nextd = curd+1;
            if(dist[next]<=nextd) continue;
            q.push({next,nextd});
            dist[next] = nextd;
        }
    }
    
    return dist;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    //1 ,2 ,3 
    // 1 2
    
    vector<vector<int>> v(n);
    for(auto road:roads){
        v[road[0]-1].push_back(road[1]-1);
        v[road[1]-1].push_back(road[0]-1);
    }
    destination--;
    vector<int> d = bfs(v,destination,n);
    for(int i=0;i<sources.size();i++){
        if(d[sources[i]-1]==INT_MAX) d[sources[i]-1]=-1;
        answer.push_back(d[sources[i]-1]);
    }
    
    
    return answer;
}