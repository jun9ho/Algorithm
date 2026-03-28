#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> v(board.size()+1,vector<int>(board[0].size()+1,0));
    for(int i=0;i<skill.size();i++){
        int type = skill[i][0];
        if(type==1) type=-1;
        else type=1;
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        v[r1][c1]     += degree * type;
        v[r2+1][c1]   += degree * type * -1;
        v[r1][c2+1]   += degree * type * -1;
        v[r2+1][c2+1] += degree * type;
    }
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[0].size();j++){
            v[i][j] +=v[i][j-1];
        }
    }
    for(int i=0;i<v[0].size();i++){
        for(int j=1;j<v.size();j++){
            v[j][i] +=v[j-1][i];
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            board[i][j] += v[i][j];
            if(board[i][j]>0) answer++;
        }
    }
    return answer;
}