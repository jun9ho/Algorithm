#include <bits/stdc++.h>

using namespace std;

void bfs(int s,vector<vector<int>>& v, vector<bool>& visit){
    
    queue<int> q;
    q.push(s);
    visit[s]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(visit[next]) continue;
            q.push(next);
            visit[next]=true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> v(n);
    //네트워크 만들고
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j) continue;
            if(computers[i][j]){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
        
    }
    //bfs를 하되 방문노드 해서 +1 하는걸로
    vector<bool> visit(n,false);
    
    for(int i=0;i<n;i++){
        if(visit[i]) continue;
        bfs(i,v,visit);
        answer++;
    }
    
    
    return answer;
}