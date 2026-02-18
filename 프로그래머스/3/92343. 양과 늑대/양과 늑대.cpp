#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void dfs(int n, int sheeps,int wolves,vector<bool> candidates,vector<int>& info,unordered_map<int,vector<int>>& graph )
{
    int size = candidates.size();
    if(!info[n]) sheeps++;
    else wolves++;
    if(sheeps>0 && wolves>=sheeps) return;
    answer = max(answer,sheeps);
    for (auto& ele : graph[n]){
        candidates[ele] = true;
    }
    for(int i=0;i<size;i++){
        if(candidates[i]){
            candidates[i] = false;
            dfs(i,sheeps,wolves,candidates,info,graph);
            candidates[i]= true;
        }
    }
    return;
    
    
}


int solution(vector<int> info, vector<vector<int>> edges) {
    
    vector<bool> candidates(info.size());
    unordered_map<int,vector<int>> graph;
    for(auto edge:edges){
        graph[edge[0]].push_back(edge[1]);
    }
    
    dfs(0,0,0,candidates,info,graph);
    
    
    return answer;
}