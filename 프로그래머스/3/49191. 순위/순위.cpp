#include <bits/stdc++.h>

using namespace std;

int winbfs(int start,vector<int> win[],int n){
    queue<int> q;
    q.push(start);
    vector<bool> vis(n,false);
    vis[start] = true;
    int num = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<win[cur].size();i++){
            if(vis[win[cur][i]]) continue;
            q.push(win[cur][i]);
            num++;
            vis[win[cur][i]]=true;
        }
        
    }
    
    
    return num;
}
int losebfs(int start,vector<int> lose[],int n){
    queue<int> q;
    q.push(start);
    vector<bool> vis(n,false);
    vis[start] = true;
    int num = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<lose[cur].size();i++){
            if(vis[lose[cur][i]]) continue;
            q.push(lose[cur][i]);
            num++;
            vis[lose[cur][i]]=true;
        }
        
    }
    
    
    return num;
    
    
    return 1;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> win[n+1];
    vector<int> lose[n+1];
    
    for(auto result : results){
        win[result[0]].push_back(result[1]);
        lose[result[1]].push_back(result[0]);
    }
    for(int i=1;i<=n;i++){
        int a = winbfs(i,win,n);
        int b = losebfs(i,lose,n);
        if((a+b)==(n-1)) answer++;
    }
    return answer;
}