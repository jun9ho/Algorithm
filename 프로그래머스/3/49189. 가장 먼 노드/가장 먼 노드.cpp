#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> v){
    
    queue<pair<int,int>> q;
    vector<int> dist(v.size(),INT_MAX);
    q.push({0,0});
    dist[0] = 0;
    while(!q.empty()){
        int curN = q.front().first;
        int curD = q.front().second;
        q.pop();
        
        for(int i=0;i<v[curN].size();i++){
            int nextN = v[curN][i];
            int nextD = curD+1;
            if(nextD>=dist[nextN]) continue;
            dist[nextN] = nextD;
            q.push({nextN,nextD});
        }
        
    }
    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> v(n);
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]-1].push_back(edge[i][1]-1);
        v[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    vector<int> d = bfs(v);
    sort(d.begin(),d.end());
    int maxx = d[d.size()-1];
    for(int i =0;i<d.size();i++){
        if(d[i]==maxx) answer++;
    }
    
    return answer;
}