#include <bits/stdc++.h>

using namespace std;


bool isMatch(string a, string b){
    int answer =0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) answer++;
    }
    if(answer== a.size()-1) return true;
    else return false;
}

int bfs(vector<int> v[], int bidx, int tidx, int size){
    vector<int> vis(size,9999);
    queue<pair<int,int>> q;
    q.push({bidx,0});
    vis[bidx] = 0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int d   = q.front().second;
        q.pop();
        if(cur==tidx){
            return d;
        }
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            int nd   = d+1;
            if(nd>=vis[next]) continue;
            q.push({next,nd});
            vis[next] = nd;
        }
    }    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(),words.end(),target)==words.end() ) return answer;
    int bidx = words.size();
    int tidx = find(words.begin(),words.end(),target) -words.begin();
    words.push_back(begin);
    
    vector<int> v[words.size()];
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if(i==j) continue;
            if(isMatch(words[i],words[j])){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    answer = bfs(v,bidx,tidx,words.size());
    
    
    return answer;
}