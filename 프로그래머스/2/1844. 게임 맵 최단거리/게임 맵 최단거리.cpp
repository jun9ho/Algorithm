#include<bits/stdc++.h>
using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x,int y,vector<vector<int>>& maps,vector<vector<bool>> &v ){
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},1});
    v[x][y] =true;
    
    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curDist = q.front().second;
        if((curX==maps.size()-1)&&(curY==maps[0].size()-1))
        {
            return curDist;
        }
        q.pop();
        for(int i=0;i<4;i++){
            
            if((curX +dx[i]>=maps.size())||(curX +dx[i]<0) ||(curY+dy[i]>=maps[0].size())||(curY+dy[i]<0)) continue;
            if(v[curX +dx[i]][curY+dy[i]]) continue;
            if(maps[curX +dx[i]][curY +dy[i]]==0) continue;
            v[curX +dx[i]][curY+dy[i]] = true;
            q.push({{curX +dx[i],curY+dy[i]},curDist+1});
        }
        
    }
    return -1;
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<vector<bool>> v(maps.size(),vector<bool>(maps[0].size(),false));
    
    answer = bfs(0,0,maps,v);
    
    return answer;
}