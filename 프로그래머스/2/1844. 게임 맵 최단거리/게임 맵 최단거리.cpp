#include<bits/stdc++.h>
using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(vector<vector<int>> maps){
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> dist(maps.size(),vector<int>(maps[0].size(),999999));
    
    q.push({{0,0},0});
    dist[0][0]=0;
    
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curd = q.front().second;
        q.pop();
        if(curx==maps.size()-1 && cury==maps[0].size()-1){
            return curd+1;
        }
        for(int i=0;i<4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int nd = curd + 1;
            if(nx<0 || ny <0 || nx>=maps.size()|| ny>=maps[0].size()) continue;
            if(maps[nx][ny]==0) continue;
            if(nd>=dist[nx][ny]) continue;
            q.push({{nx,ny},nd});
            dist[nx][ny] = nd;
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    answer = bfs(maps);
    
    return answer;
}