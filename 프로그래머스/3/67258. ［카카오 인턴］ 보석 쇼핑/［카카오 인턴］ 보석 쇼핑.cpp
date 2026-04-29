#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> m;
    if(gems.size()==1) return {1,1};
    int glen = gems.size();
    int left =0;
    int right =0;
    int size=0;
    
    set<string> s;
    for(int i=0;i<glen;i++){
        s.insert(gems[i]);
    }
    int tsize= s.size(); // 보석 종류개수

    int len = INT_MAX;
    int mleft =INT_MAX;
    int mright =INT_MAX;
    for(int i=0;i<glen;i++){
        
        m[gems[i]]++;
        if(m[gems[i]]==1) size++;
        right =i;
        
        if(size==tsize){
            while(left<=right){
                m[gems[left]]--;
                if(m[gems[left]]==0){
                    size--;
                    
                    if(len>right-left+1){
                        len = right-left+1;
                        mleft=left;
                        mright=right;
                        
                    }
                    left++;
                    break;
                }
                left++;
            }
        }
        
    }
    
    
    return {mleft+1,mright+1};
}