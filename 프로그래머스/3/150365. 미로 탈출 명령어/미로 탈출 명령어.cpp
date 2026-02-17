#include <bits/stdc++.h>

using namespace std;
//d아,l왼,r오,u위

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

string bfs(int n,int m, int curx,int cury,int endx,int endy, int k){//k는 가능거리
    string s ="";
    queue<pair<int,int>> q;
    q.push({curx,cury});
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(abs(endx-nx)+abs(endy-ny)>k) continue;
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            q.push({nx,ny});
            k--;
            if(i==0)s+='d';
            if(i==1)s+='l';
            if(i==2)s+='r';
            if(i==3)s+='u';
            break;
        }
    }
    
    
    return s;
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    //n,m 격자에서 x-1,y-1 출발 r-1,c-1 도착 k길이만큼
    int len = abs(r-x)+abs(c-y);
    if((k-len)%2==1) return "impossible";
    
    answer= bfs(n,m,x-1,y-1,r-1,c-1,k);
    if(answer.size()==0) return "impossible";
    
    return answer;
}