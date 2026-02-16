#include <bits/stdc++.h>


using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> v(board.size()+1,vector<int>(board[0].size()+1,0));
    for(int i=0;i<skill.size();i++){
        int type = skill[i][0];// 1 공격, 2 회복
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];//
        
        if(type==1) degree*=-1;
        //r1,c1,r2,c2
        //r1<= <=r2 -> degree만큼
        //c1 c2
        v[r1][c1] +=   degree;
        v[r1][c2+1] += -degree;
        v[r2+1][c1] += -degree;
        v[r2+1][c2+1] += degree;
    }
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[0].size();j++){
            v[i][j]+=v[i][j-1];
        }
    }
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            v[i][j]+=v[i-1][j];
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            board[i][j]+=v[i][j];
            if(board[i][j]>0) answer++;
        }
    }
    //0,0,3,4
        //-4 0 0 0 0
        //-4 0 0 0 0
        //-4 0 0 0 0
        //-4 0 0 0 0
        //2,0,2,3->2
        
        //0 0 0 0 0
        //0 0 0 0 0
        //-2 0 0 0 2
        //0 0 0 0 0
        
        //1 0 0 0 0
        //1 0 0 0 0
        //-1 0 0 0 0 2
        //1 0 0 0 0 0
        
        //1,0,3,1,2
        //0 0 0 0 0
        //2 0 -2 0 0
        //2 0 -2 0 0
        //2 0 -2 0 0
    return answer;
}