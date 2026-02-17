#include <bits/stdc++.h>

using namespace std;

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

int bfs(int curx, int cury, int endx, int endy,vector<vector<int>> v){
    
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> dist(102,vector<int>(102,10000));
    q.push({{curx,cury},0});
    dist[curx][cury]=0;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cd = q.front().second;
        q.pop();
        if(cx==endx && cy==endy){
            return cd;
        }
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            int nd = cd+1;
            if((nx<=1)||(ny<=1)||(nx>=101)||(nx>=101)) continue;
            if(!v[nx][ny]) continue;
            if(dist[nx][ny]<=nd) continue;
            dist[nx][ny]=nd;
            q.push({{nx,ny},nd});
        }
        
    }
    
    
    
    
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    vector<vector<int>> v(102,vector<int>(102,0));
    for(int i=0;i<rectangle.size();i++){
        for(int a=rectangle[i][0]*2;a<=rectangle[i][2]*2;a++){
            for(int b=rectangle[i][1]*2;b<=rectangle[i][3]*2;b++){
                v[a][b]=1;
            }
        }
    }
    for(int i=0;i<rectangle.size();i++){
        for(int a=rectangle[i][0]*2+1;a<rectangle[i][2]*2;a++){
            for(int b=rectangle[i][1]*2+1;b<rectangle[i][3]*2;b++){
                v[a][b]=0;
            }
        }
    }
    answer = bfs(characterX*2, characterY*2, itemX*2, itemY*2, v);
    
    return answer/2;
}