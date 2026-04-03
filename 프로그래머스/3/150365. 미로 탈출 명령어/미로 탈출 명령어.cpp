#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,0,-1};// d l r u
int dy[4] = {0,-1,1,0};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    x--;y--;r--;c--;
    // dlru
    // (du) (lr) (rl) (ud) 
    // dllrl
    int a = abs(r-x) + abs(c-y);
    if(k<a || (k-a)%2!=0) return "impossible";
    
    vector<vector<int>> v(n,vector<int>(m,0));
    int curx = x;
    int cury = y;
    map<int,char> mp;
    mp[0]='d';
    mp[1]='l';
    mp[2]='r';
    mp[3]='u';
    while(1){
        int b = abs(r-curx) + abs(c-cury);//얼마나 남았는지
        if(b==k){
            int diffx = r-curx;// r>curx 면 r이 더 아래쪽
            int diffy = c-cury;// c>cury 면 c가 더 오른쪽
            if(diffx>=0){
                for(int i=0;i<diffx;i++){
                    answer+='d';
                }
                if(diffy>=0){
                    for(int j=0;j<diffy;j++){
                        answer+='r';
                    }
                }
                else{
                    for(int j=0;j<(-diffy);j++){
                        answer+='l';
                    }
                }
                
            }
            else if(diffx<0){
                if(diffy>=0){
                    for(int j=0;j<diffy;j++){
                        answer+='r';
                    }
                }
                else{
                    for(int j=0;j<(-diffy);j++){
                        answer+='l';
                    }
                }
                for(int i=0;i<(-diffx);i++){
                    answer+='u';
                }
            }
            
            
            break;
        }
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            if(nx>=n || ny>=m|| nx<0 ||ny<0) continue;
            answer+=mp[i];
            k--;
            curx=nx;
            cury=ny;
            break;
        }
        
    }
    
    
    
    
    return answer;
}