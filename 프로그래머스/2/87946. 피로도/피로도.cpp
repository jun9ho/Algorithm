#include <bits/stdc++.h>

using namespace std;

//"최소 필요 피로도"
//dfs()
int answer = -1;
vector<bool> vis(8,false);

void dfs(int idx, int cur, int size, vector<vector<int>>& dungeons){
    
    if(idx==size){
        return;
    }
    
    for(int i=0;i<size;i++){
        if(vis[i]) continue;
        if(cur>=dungeons[i][0]){
            answer = max(answer,idx+1);
            vis[i]=true;
            dfs(idx+1,cur-dungeons[i][1],size,dungeons);
            vis[i]=false;
        }
        
        
    }
    
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(0,k,dungeons.size(),dungeons);
    
    return answer;
}