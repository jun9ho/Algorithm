#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int>b){
    
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string regex="{},";
    for(char& c : s){
        if(regex.find(c)!=string::npos){
            c=',';
        }
    }
    stringstream ss(s);
    string token;
    map<int,int> m;
    while(getline(ss,token,',')){
        if(token.size()==0) continue;
        m[stoi(token)]++;
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    return answer;
}