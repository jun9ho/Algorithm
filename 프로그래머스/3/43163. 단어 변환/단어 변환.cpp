#include <bits/stdc++.h>

using namespace std;


bool match(string a,string b){
    if(a.size()!=b.size()) return false;
    int cnt =0;
    int len = a.size();
    for(int i=0;i<len;i++){
        if(a[i]==b[i]) cnt++;
    }
    if(cnt==len-1) return true;
    else return false;
}

int bfs(int idx, vector<vector<int>> v){
    
    int len = v.size();
    
    queue<pair<int,int>> q;
    vector<int> dist(len,INT_MAX);
    q.push({0,0});
    dist[0]=0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int curd = q.front().second;
        q.pop();
        if(cur==idx){
            return dist[cur];
        }
        
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            int nd = curd+1;
            if(nd>=dist[next]) continue;
            q.push({next,nd});
            dist[next]=nd;
        }
    }
    return dist[idx];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    auto iter = find(words.begin(),words.end(),target);
    if(iter==words.end()) return 0;
    iter = find(words.begin(),words.end(),begin);
    if(iter==words.end()) words.insert(words.begin(),begin);
    
    vector<vector<int>> v(words.size());
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            if(i==j) continue;
            if(match(words[i],words[j])){
                v[i].push_back(j);
                v[j].push_back(i);
            }
            
        }
    }
    
    auto tidx = find(words.begin(),words.end(),target);
    answer = bfs(tidx-words.begin(),v);
    
    
    
    return answer;
}