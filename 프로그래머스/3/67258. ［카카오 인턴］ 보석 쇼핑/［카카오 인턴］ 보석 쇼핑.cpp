#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> m;
    for(auto gem:gems){
        m[gem]++;
    }
    int gs = m.size();
    
    map<string,int> g;
    int sz = 0;
    int idx =0;
    int ml = INT_MAX;
    int mleft =INT_MAX;
    int mright =INT_MAX;
    for(int i=0;i<gems.size();i++){
        g[gems[i]]++;
        if(g[gems[i]]==1) sz++;
        if(sz==gs){
            while(idx<=i){
                g[gems[idx]]--;
                if(g[gems[idx]]==0){
                    sz--;
                    if(ml > i-idx+1){
                        ml=i-idx+1;
                        mleft= idx+1;
                        mright = i+1;
                    }
                    idx++;
                    break;
                }
                idx++;
            }
        }
    }
    
    
    return {mleft,mright};
}