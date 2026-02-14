#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> v;
    int size = 0;
    for(int i=0;i<operations.size();i++){
        stringstream ss(operations[i]);
        string token;
        int a=-1,b=-1;
        while(getline(ss,token,' ')){
            if(token=="I"||token=="D"){
                if(token=="I"){
                    a=0;
                }
                else if(token=="D"){
                    a=1;
                }
            }
            else{
                b=stoi(token);
            }
        }
        if(a==0){
            v.push_back(b);
            sort(v.begin(),v.end(),greater<>());
        }
        else{
            if(v.size()==0){
                continue;
            }
            if(b==1){
                v.pop_front();
            }
            else if(b==-1){
                v.pop_back();
            }
        }
    }
    if(v.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(v.front());
        answer.push_back(v.back());
    }
    return answer;
}