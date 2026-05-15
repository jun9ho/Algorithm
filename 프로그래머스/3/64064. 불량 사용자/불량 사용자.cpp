#include <bits/stdc++.h>

using namespace std;

map<vector<string>,int> m;

bool match(string a, string b){
    if(a.size()!=b.size()) return false;
    int cnt=0;
    int len = a.size();
    for(int i=0;i<len;i++){
        if(a[i]==b[i] ||b[i]=='*') continue;
        else return false;
    }
    return true;
}

void dfs(int idx,vector<string>& user_id, vector<string>& banned_id,vector<bool>& vis,vector<string> v){
    if(idx==banned_id.size()){
        sort(v.begin(),v.end());
        m[v]++;
        return;
    }
    
    for(int i=0;i<user_id.size();i++){
        if(vis[i]) continue;
        if(match(user_id[i],banned_id[idx])){
            vis[i]=true;
            v.push_back(user_id[i]);
            dfs(idx+1,user_id,banned_id,vis,v);
            v.pop_back();
            vis[i]=false;
        }
        
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<bool> vis(user_id.size(),false);
    dfs(0,user_id,banned_id,vis,{});
    
    
    
    return m.size();
}