#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    //1 : 5
    //2 : 1, 10 , 25
    //3 : 6, 4,   15,50,2,   30, 20, 125
    //4
    if(N==number) return 1;
    map<int,bool>m;
    m[N]=true;
    vector<int> v[9];
    v[1].push_back(N);
    for(int i=2;i<=8;i++){//i는 총합
        string s="";
        for(int l=0;l<i;l++){
            s+=to_string(N);
        }
        v[i].push_back(stoi(s));
        m[stoi(s)]=true;
        
        for(int j=1;j<=i/2;j++){
            int a = j;   //v[a]
            int b = i-j; //v[b]
            for(int n=0;n<v[a].size();n++){
                for(int z=0;z<v[b].size();z++){
                    int t1 = v[a][n]+v[b][z];
                    int t2 = abs(v[a][n]-v[b][z]);
                    int t3 = v[a][n]*v[b][z];
                    int t4 = 0;
                    if(min(v[a][n],v[b][z])!=0) t4 = max(v[a][n],v[b][z])/min(v[a][n],v[b][z]);
                    if(!m[t1]){
                        m[t1]=true;
                        v[i].push_back(t1);
                    }
                    if(!m[t2]){
                        m[t2]=true;
                        v[i].push_back(t2);
                    }
                    if(!m[t3]){
                        m[t3]=true;
                        v[i].push_back(t3);
                    }
                    if(!m[t4]){
                        m[t4]=true;
                        v[i].push_back(t4);
                    }
                    if(m[number]) return i;
                }
            }
            
            
        }
    }
    
    
    
    return -1;
}