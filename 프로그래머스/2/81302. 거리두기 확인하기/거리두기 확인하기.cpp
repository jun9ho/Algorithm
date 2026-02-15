#include <bits/stdc++.h>

using namespace std;

int dx1[4] = {1,-1,0,0};
int dy1[4] = {0,0,1,-1};
int dx2[4] = {2,-2,0,0};
int dy2[4] = {0,0,2,-2};
int dx3[4] = {1,-1,-1,1};
int dy3[4] = {1, 1,-1,-1};

bool check(int curx,int cury,vector<string> &place){
    
    for(int i=0;i<4;i++){
        int dx = curx+dx1[i];
        int dy = cury+dy1[i];
        if((dx<0)||(dy<0)||(dx>4)||(dy>4)) continue;
        if(place[dx][dy]=='P') return false;
    }
    for(int i=0;i<4;i++){
        int dx = curx+dx2[i];
        int dy = cury+dy2[i];
        if((dx<0)||(dy<0)||(dx>4)||(dy>4)) continue;
        if(place[dx][dy]=='P'){
            if(place[dx-dx1[i]][dy-dy1[i]]!='X') return false;
        }
    }
    for(int i=0;i<4;i++){
        int dx = curx+dx3[i];
        int dy = cury+dy3[i];
        if((dx<0)||(dy<0)||(dx>4)||(dy>4)) continue;
        if(place[dx][dy]=='P'){
            if((place[curx][dy]!='X')||(place[dx][cury]!='X')) return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        bool is = true;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(places[i][j][k]=='P'){
                    is = check(j,k,places[i]);
                }
                if(!is) break;
            }
            if(!is) break;
        }
        if(is) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}