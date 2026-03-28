#include <bits/stdc++.h>

using namespace std;



int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    int bit = (1<<col);
    unordered_set<int> key;
    for(int i=1;i<bit;i++){
        set<vector<string>> s;
        for(int j=0;j<row;j++){//6
            vector<string> v;
            for(int k=0;k<col;k++){//4
                if(((1<<k) & i) == 0) continue;
                v.push_back(relation[j][k]);
            }
            s.insert(v);
        }
        if(s.size()==row){
            bool is = true;
            for(auto iter=key.begin();iter!=key.end();iter++){
                if(((*iter) & (i)) == (*iter)){
                    is= false;
                    break;
                }
            }
            if(is) key.insert(i);
        }
    }
    
    return key.size();
}