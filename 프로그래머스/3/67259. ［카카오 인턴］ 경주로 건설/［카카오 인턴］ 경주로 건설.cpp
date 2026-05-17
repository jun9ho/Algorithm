#include <bits/stdc++.h>

using namespace std;

int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
        //  0 1 2  3
int bfs(vector<vector<int>> board){
    int n = board.size();
    queue<tuple<int,int,int,int>> q;//x,y,money(dist), prev(0~3) 
    vector<vector<vector<int>>> dist(n,vector<vector<int>>(n,vector<int>(4,INT_MAX)));
    for(int i=0;i<4;i++){
        dist[0][0][i]=0;
    }
    q.push({0,0,0,-1});
    while(!q.empty()){
        auto [cx,cy,cd,prev] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            auto nx = cx+dx[i];
            auto ny = cy+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(board[nx][ny])continue;
            auto nd = cd;
            if(prev==i||prev==-1) nd+=100;
            else nd+=600;
            if(dist[nx][ny][i]<=nd) continue;
            dist[nx][ny][i]= nd;
            q.push({nx,ny,nd,i});
        }
    }
    int minn =INT_MAX;
    for(int i=0;i<4;i++){
        minn=min(minn,dist[n-1][n-1][i]);
    }
    return minn;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    answer = bfs(board);
    
    return answer;
}