#include <bits/stdc++.h>


using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    //학번 이건 뺴고 두개씩묶어
    //이름,전공
    //학년 남았지 이건안돼
    unordered_set<int> key;
    //key가 이제 0001~ 1111까지 해야되거든?
    int size = relation.size();// size와 같아야함 s의 size와
    for(int i=1;i<pow(2,relation[0].size());i++){
        // i를 모아야돼 그다음에 여기서 모인 i들끼리 비교해서 포함하고있는 큰건 빼줘야돼 그중 가장큰거
        set<vector<string>> s;
        for(int a=0;a<size;a++){//6
            //if(1<<a & i ==0) continue;
            vector<string> v;
            
            for(int b=0;b<relation[0].size();b++){//4
                if(((1<<b) & i) ==0) continue;
                v.push_back(relation[a][b]);
            }
            s.insert(v);
        }
        if(s.size()==size){
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
    // 1000 1100 1010 10001 1110 1101 1011 1111 0110 0111
    // 이 키들 중에 1의 개수가 가장 작은거에서 그걸 포함하는 key들을 제외해

    return key.size();
}