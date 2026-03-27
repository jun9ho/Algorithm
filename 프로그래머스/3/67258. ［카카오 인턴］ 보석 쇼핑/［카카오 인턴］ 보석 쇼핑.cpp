#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    set<string> s1;
    
    for(int i=0;i<gems.size();i++){
        s1.insert(gems[i]);
    }
    
    int size = s1.size();
    int begin = 0;
    int end = 0;
    int len = 100001;
    int mb=0,me = 0;
    
    set<string> s;
    map<string,int> m;
    for(int i=0;i<gems.size();i++){
        s.insert(gems[i]);
        m[gems[i]]++;
        end = i;
        if(s.size()==size){
            while(s.size()==size){
                m[gems[begin]]--;
                if(m[gems[begin]]<=0){
                    s.erase(gems[begin]);
                    if(end-begin<len){
                        mb = begin;
                        me = end;
                        len = me-mb;
                    }
                    begin++;
                    break;
                }
                begin++;
            }

        }
    }
    
    
    return {mb+1,me+1};
}