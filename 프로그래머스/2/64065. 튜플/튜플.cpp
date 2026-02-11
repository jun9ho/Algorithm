#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a,pair<int,int>b){
    
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> m;
    for (char& c : s){
        if (string(",}{").find(c) != string::npos)
            c = ',';
    }
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        if(token.length()!=0) m[stoi(token)]++;
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),comp);
    
    
    //, 구분으로 숫자 파싱해서 가져오고 -> 이건 string이기에 stoi해가지고 map으로가져오고
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}