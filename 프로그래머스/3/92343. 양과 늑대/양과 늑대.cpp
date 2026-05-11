#include <bits/stdc++.h>

using namespace std;
int answer = 0;
void bdfs(int sheep,int wolf,vector<int>& info, vector<vector<int>>& v,vector<bool>& candidate,vector<bool>& visited){
    
    if(wolf>=sheep) return;
    answer= max(answer,sheep);
    
    for(int i=0;i<candidate.size();i++){
        if(candidate[i]){
            for(int j=0;j<v[i].size();j++){
                int next = v[i][j];//1
                if(visited[next]) continue;
                candidate[next] = true;
                visited[next] = true;
                int sw = info[next];
                if(sw==0) bdfs(sheep+1,wolf,info,v,candidate,visited);
                else bdfs(sheep,wolf+1,info,v,candidate,visited);
                visited[next] = false;
                candidate[next] = false;
            }
        }
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<vector<int>> v(info.size());
    for(auto edge:edges){
        v[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(info.size(),false);
    vector<bool> candidate(info.size(),false);
    candidate[0]=true;
    visited[0] = true;
    
    bdfs(1,0,info,v,candidate,visited);
    
    
    return answer;
}