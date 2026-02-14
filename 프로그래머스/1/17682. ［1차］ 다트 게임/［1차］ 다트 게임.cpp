#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score(4,0);
    string s ="";
    int cnt =1;
    for(int i=0;i<dartResult.size();i++){
        char a = dartResult[i];
        if(a=='*'||a=='#'){
            if(a=='*'){
                score[cnt-1]*=2;
                score[cnt-2]*=2;     
            }
            if(a=='#'){
                score[cnt-1]*=-1;   
            }
            continue;
        }
        if(a>='A' && a<='Z'){
            int k = stoi(s);
            if(a=='S'){
                score[cnt] = k;
            }
            else if(a=='D'){
                score[cnt] = pow(k,2);
            }
            else if(a=='T'){
                score[cnt] = pow(k,3);
            }
            s="";
            cnt++;
            continue;
        }
        s+=a;
    }
    
    
    return score[1]+score[2]+score[3];
}