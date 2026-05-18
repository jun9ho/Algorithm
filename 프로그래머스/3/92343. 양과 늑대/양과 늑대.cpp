#include <bits/stdc++.h>

using namespace std;

int answer = 0;
void dfs(int n,vector<int>& info, vector<vector<int>>& v,int sheep,int wolf,vector<bool> candidate){
    
    if(wolf>=sheep) return;
    
    answer = max(sheep,answer);
    
    for(int i=0;i<candidate.size();i++){
        if(candidate[i]){
            for(int j=0;j<v[i].size();j++){
                //v[i][j] 다음 노드
                if(candidate[v[i][j]]) continue;
                candidate[v[i][j]]=true;
                if(info[v[i][j]]) dfs(n,info,v,sheep,wolf+1,candidate);
                else dfs(n,info,v,sheep+1,wolf,candidate);
                candidate[v[i][j]]=false;
            }
            
        }
    }
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();// 총 노드 수
    vector<vector<int>> v(n);// 트리
    for(auto edge:edges){
        v[edge[0]].push_back(edge[1]);
    }
    vector<bool> candidate(n,false);
    candidate[0]=true;
    dfs(n,info,v,1,0,candidate);
    
    
    
    return answer;
}