#include <bits/stdc++.h>

using namespace std;

map<vector<string>,int> fa;
map<string,vector<string>> m1;
map<pair<string,string>,int> m2;
void dfs(string cur,int cursize, int size, vector<string> answer){
    if(cursize==size){
        fa[answer]++;
        return;
    }
    
    for(int i=0;i<m1[cur].size();i++){
        if(m2[{cur,m1[cur][i]}]==0) continue;
        m2[{cur,m1[cur][i]}]--;
        answer.push_back(m1[cur][i]);
        dfs(m1[cur][i], cursize+1,size,answer);
        answer.pop_back();
        m2[{cur,m1[cur][i]}]++;
    }
    
    
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for(int i=0;i<tickets.size();i++){
        m1[tickets[i][0]].push_back(tickets[i][1]);
        m2[{tickets[i][0],tickets[i][1]}]++;
    }
    for(auto iter=m1.begin();iter!=m1.end();iter++){
        sort((iter->second).begin(),(iter->second).end());
    }
    // ICN: ATL SFO
    // SFO: ATL
    // ATL: ICN SFO
    
    dfs("ICN",0,tickets.size(),{"ICN"});
    
    
    return fa.begin()->first;
}