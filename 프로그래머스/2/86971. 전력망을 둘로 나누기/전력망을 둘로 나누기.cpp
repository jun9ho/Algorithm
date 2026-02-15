#include <bits/stdc++.h>

using namespace std;

int bfs(int n,vector<int> v[],vector<int>& wire){
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(0);
    vis[0]=true;
    int cnt = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(vis[next]) continue;
            if((cur==(wire[0]-1))&&(next==(wire[1]-1))) continue;
            if((cur==(wire[1]-1))&&(next==(wire[0]-1))) continue;
            q.push(next);
            vis[next]=true;
            cnt++;
        }
        
    }
    int k = n - cnt;
    return abs(k-cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<int> v[n];
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int minn = 9999;
    for(int i=0;i<wires.size();i++){
        minn= min(minn,bfs(n,v,wires[i]));
    }
    
    return minn;
}