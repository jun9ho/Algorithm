#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> s(gems.begin(),gems.end());
    int size = s.size();
    int L=0,R=0,bestL=0,bestR=gems.size()-1;
    int length = gems.size()+1;
    unordered_map<string,int> m;
    int have = 0;
    for(R=0;R<gems.size();R++){
        m[gems[R]]++;
        if(m[gems[R]]==1) have++;
        while(have==size){
            if(length>R-L+1){
                bestR=R;
                bestL=L;
                length = R-L+1;
            }
            m[gems[L]]--;
            if(m[gems[L]]==0) have--;
            L++;
            
        }
        
    }
    
    
    
    
    return {bestL+1,bestR+1};
}
