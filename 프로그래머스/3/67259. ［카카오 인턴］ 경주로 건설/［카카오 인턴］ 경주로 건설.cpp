#include <bits/stdc++.h>

using namespace std;
using T=tuple<int,int,int,int>;

// 직선 도로 100원, 코너 500원

int dx[4] ={1,0,-1,0};
int dy[4] ={0,1,0,-1};



int bfs(vector<vector<int>> board){
    int n = board.size();
    vector<vector<vector<int>>> dist(n,vector<vector<int>>(n,vector<int>(4,INT_MAX)));
    priority_queue<T,vector<T>,greater<T>> q; //dist,pre, x, y
    q.push({0,0,0,-1});
    for(int i=0;i<4;i++){
        dist[0][0][i]=0;
    }
    while(!q.empty()){
        auto [curd,curx,cury,pre] = q.top();
        q.pop();
        if(curx==n-1 && cury==n-1) return curd;

        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            int nd;
            
            if(nx>=n || ny>=n || nx<0 || ny<0) continue;
            if(board[nx][ny]) continue;
            
            if(pre==-1)nd = curd+100;
            else if (pre!=i) nd = curd+600;
            else nd=curd+100;
            
            if(dist[nx][ny][i]<=nd) continue;
            
            dist[nx][ny][i]= nd;
            q.push({nd,nx,ny,i});
        }
        
        
    }
    
    return min(min(dist[n-1][n-1][0],dist[n-1][n-1][1]),min(dist[n-1][n-1][2],dist[n-1][n-1][3]));
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    answer = bfs(board);
    
    
    return answer;
}