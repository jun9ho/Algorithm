#include <bits/stdc++.h>

using namespace std;


bool isRight0(int x, int y, int a, map<vector<int>,bool> m){
    if(m[{x,y-1,0}] || m[{x-1,y,1}] || m[{x,y,1}] || y==0 ) return true;
    else return false;
    
}
bool isRight1(int x, int y, int a, map<vector<int>,bool> m){
    if(m[{x,y-1,0}] || m[{x+1,y-1,0}] || (m[{x-1,y,1}] && m[{x+1,y,1}])) return true;
    else return false;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    
    vector<vector<int>> v;// v[][0]; x v[][1] u v[][2] 0(기둥) 1(보) 
    map<vector<int>,bool> m;
    
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];//x좌표
        int y = build_frame[i][1];//y좌표
        int a = build_frame[i][2];// 0은 기둥 1은 보
        int b = build_frame[i][3];// 0은 삭제 1은 설치
        if(a==0){//기둥
            if(b==1){//설치
                if(isRight0(x,y,a,m) ){
                    m[{x,y,a}]=true;
                }
            }
            if(b==0){
                m[{x,y,a}]= false;
                if(m[{x,y+1,0}]==true){
                    if(!isRight0(x,y+1,0,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
                if(m[{x,y+1,1}]==true){
                    if(!isRight1(x,y+1,1,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
                if(m[{x-1,y+1,1}]==true){
                    if(!isRight1(x-1,y+1,1,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
            }
        }
        if(a==1){//보
            if(b==1){//설치
                if(isRight1(x,y,a,m)){
                    m[{x,y,a}]=true;
                }
            }
            if(b==0){//삭제
                m[{x,y,a}]= false;
                if(m[{x,y,0}]==true){
                    if(!isRight0(x,y,0,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
                if(m[{x+1,y,0}]==true){
                    if(!isRight0(x+1,y,0,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
                if(m[{x-1,y,1}]==true){
                    if(!isRight1(x-1,y,1,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
                if(m[{x+1,y,1}]==true){
                    if(!isRight1(x+1,y,1,m)){
                        m[{x,y,a}]= true;
                        continue;
                    }
                }
            }
        }
        
        
    }
    vector<vector<int>> answer;
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(iter->second) answer.push_back({iter->first[0],iter->first[1],iter->first[2]});
    }
    return answer;
}