#include <bits/stdc++.h>

using namespace std;

bool match(string a, string b){
    if(a.length()!=b.length()) return false;
    for(int i=0;i<a.length();i++){
        if(a[i]=='*') continue;
        if(a[i]!=b[i]) return false;
    }
    return true;
}

void dfs(int cur,int mask,unordered_set<int>& s, vector<int> v[],int banN){
    if(cur==banN){
        s.insert(mask);
        return;
    }
    
    for(int i=0;i<v[cur].size();i++){
        int k = v[cur][i];// user index
        if((mask)&(1<<k)) continue;
        dfs(cur+1,mask|1<<k,s,v,banN);
    }
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    unordered_set<int> s;
    int userN = user_id.size();
    int banN = banned_id.size();
    vector<int> v[banN];
    for(int i=0;i<banN;i++){
        for(int j=0;j<userN;j++){
            if(match(banned_id[i],user_id[j])){
                v[i].push_back(j);
            }
        }
    }
    dfs(0,0,s,v,banN);
    
    return s.size();
}