#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> prev,next;
    for(int i=0;i<n;i++){
        prev.push_back(i-1);
        next.push_back(i+1);
    }
    next[n-1]= -1;
    vector<char> alive(n, 'O');
    stack<int> st;
    
    for(int i=0;i<cmd.size();i++){
        string s = cmd[i];
        if(s.size()!=1){
            stringstream ss(s);
            string token;
            getline(ss,token,' ');
            getline(ss,token,' ');
            int a = stoi(token);
            if(s[0]=='U'){ //위
                for(int j=0;j<a;j++){
                    if(prev[k]==-1) break;
                    k= prev[k];
                }
            }
            if(s[0]=='D'){ //아래
                for(int j=0;j<a;j++){
                    if(next[k]==-1) break;
                    k = next[k];
                }
            }
            
        }
        else{
            if(s[0]=='C'){//삭제
                alive[k] = 'X';
                st.push(k);
                if(prev[k]!=-1)next[prev[k]] = next[k];
                if(next[k]!=-1)prev[next[k]] = prev[k];
                if(next[k]!=-1)k = next[k];
                else k= prev[k];
            }
            if(s[0]=='Z'){//복구
                if(st.size()==0) continue;
                int t = st.top();
                alive[t] = 'O';
                st.pop();
                if(prev[t]!=-1) next[prev[t]] = t;
                if(next[t]!=-1) prev[next[t]] = t;
            }
        }
    }

    return string(alive.begin(), alive.end());
}