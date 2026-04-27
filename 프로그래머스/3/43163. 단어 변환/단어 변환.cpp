#include <bits/stdc++.h>

using namespace std;


bool matching(string a, string b){
    if(a.size()!=b.size()) return false;
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) cnt++;
    }
    if(cnt==1) return true;
    else return false;
}

int bfs(int bidx,int tidx, vector<vector<int>> v){
    queue<pair<int,int>> q;
    vector<int> dist(v.size(),INT_MAX);
    q.push({bidx,0});
    dist[bidx] = 0;
    
    while(!q.empty()){
        int curIdx = q.front().first;
        int curDist = q.front().second;
        q.pop();
        if(tidx==curIdx){
            return curDist;
        }
        for(int i=0;i<v[curIdx].size();i++){
            int nextIdx = v[curIdx][i];
            int nextDist = curDist+1;
            if(nextDist>=dist[nextIdx]) continue;
            dist[nextIdx] = nextDist;
            q.push({nextIdx,nextDist});
        }    
    }
    
    return dist[tidx];
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int bidx = find(words.begin(),words.end(),begin) - words.begin();
    int tidx = find(words.begin(),words.end(),target) - words.begin();

    if(tidx==words.size()){
        return 0;
    }
    
    if(bidx==words.size()){
        words.push_back(begin);
    }
    
    vector<vector<int>> v(words.size());
    
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if(matching(words[i],words[j])){
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    answer = bfs(bidx,tidx,v);
    
    return answer;
}