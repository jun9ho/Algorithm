#include <bits/stdc++.h>

using namespace std;

map<vector<string>,int> m;

bool match(string user, string ban){
    if(user.size()!=ban.size()) return false;
    int len =user.size();
    for(int i=0;i<len;i++){
        if(ban[i]=='*') continue;
        if(user[i]!=ban[i]) return false;
    }
    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id,  vector<bool>& v,int cur,vector<string> all){
    
    if(cur==banned_id.size()){
        sort(all.begin(),all.end());
        m[all]++;
        return;        
    }
    
    int len = user_id.size();
    for(int i =0;i<len;i++){
        if(v[i]) continue;
        if(!match(user_id[i],banned_id[cur])) continue;
        v[i] = true;
        all.push_back(user_id[i]);
        dfs(user_id,banned_id,v,cur+1,all);
        all.pop_back();
        v[i] = false;
        
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer =0 ;
    vector<bool> v(user_id.size(),false);
    dfs(user_id,banned_id,v,0,{});
    
    return m.size();
}