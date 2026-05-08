#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){
    
    vector<vector<int>> new_key(key.size(),vector<int>(key[0].size(),0));
    int ks = key.size();
    for(int i=0;i<ks;i++){
        for(int j=0;j<ks;j++){
            new_key[i][j]= key[ks-1-j][i]; // new_key 의 j + key의 i = 3
        }
    }
    
    return new_key;
}

bool check(vector<vector<int>> key, vector<vector<int>> lock,int cnt){
    int ls = lock.size();
    int ks = key.size();
    for(int i=0;i<ls-ks+1;i++){
        for(int j=0;j<ls-ks+1;j++){
            int ccnt = 0;
            bool isRight = true;
            for(int a=0;a<ks;a++){
                for(int b=0;b<ks;b++){
                    if(lock[i+a][j+b] == -1) continue;
                    if(key[a][b]+lock[i+a][j+b]==2){
                        isRight=false;
                        break;
                    }
                    if(lock[i+a][j+b] == 0 && key[a][b] == 1) ccnt++;
                }
                if(!isRight) break;
            }
            if(cnt==ccnt) return true;
        }
    }
    
    
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int ls = lock.size();
    int ks = key.size();
    int cnt =0;
    vector<vector<int>> new_lock(ls+(ks-1)*2,vector<int>(ls+(ks-1)*2,-1));
    for(int i=ks-1;i<ks-1+ls;i++){
        for(int j=ks-1;j<ks-1+ls;j++){
            new_lock[i][j]=lock[i-ks+1][j-ks+1];
            if(!lock[i-ks+1][j-ks+1]) cnt++;
        }
    }
    
    vector<vector<vector<int>>> keys;
    //키 회전 -> 4개얻기
    keys.push_back(key);
    for(int i=0;i<3;i++){
        vector<vector<int>> new_key = rotate(keys[i]);
        keys.push_back(new_key);
    }
    
    //되는지 안되는지 확인
    
    for(int i=0;i<4;i++){
        if(check(keys[i],new_lock,cnt)) return answer;
    }
    
    return false;
}