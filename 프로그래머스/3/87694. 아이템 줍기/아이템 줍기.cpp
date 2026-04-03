#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int bfs(vector<vector<int>> v,int characterX, int characterY, int itemX, int itemY ){
    queue<pair<pair<int,int>,int>> q;
    q.push({{characterX,characterY},0});
    vector<vector<int>> dist(v.size(),vector<int>(v[0].size(),INT_MAX));
    dist[characterX][characterY] =0;
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curd = q.front().second;
        q.pop();
        if(curx==itemX && cury == itemY){
            return curd;
        }
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            int nd = curd+1;
            if(nx>100||ny>100||nx<1||ny<1) continue;
            if(nd>=dist[nx][ny]) continue;
            if(v[nx][ny]==0) continue;
            q.push({{nx,ny},nd});
            dist[nx][ny]=nd;
        }
    }
    return 0;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> v(101,vector<int>(101,0));
    for(int i=0;i<rectangle.size();i++){
        int ldx = rectangle[i][0];
        int ldy = rectangle[i][1];
        int rux = rectangle[i][2];
        int ruy = rectangle[i][3];
        ldx*=2;
        ldy*=2;
        rux*=2;
        ruy*=2;
        for(int j=ldx;j<=rux;j++){
            for(int k=ldy;k<=ruy;k++){
                v[j][k]=1;
            }
        }
    }
    for(int i=0;i<rectangle.size();i++){
        int ldx = rectangle[i][0];
        int ldy = rectangle[i][1];
        int rux = rectangle[i][2];
        int ruy = rectangle[i][3];
        ldx*=2;
        ldy*=2;
        rux*=2;
        ruy*=2;
        for(int j=ldx+1;j<rux;j++){
            for(int k=ldy+1;k<ruy;k++){
                v[j][k]=0;
            }
        }
    }
    
    answer = bfs(v,characterX*2,characterY*2,itemX*2,itemY*2);
    
    
    
    return answer/2;
}