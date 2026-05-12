#include <bits/stdc++.h>


using namespace std;


bool sorted(pair<int,int> a, pair<int,int>b){
    
    if(a.first==b.first) return a.second<b.second;
    
    return a.first>b.first;
}
bool sorted2(pair<string,int> a, pair<string,int> b){
    
    return a.second>b.second;
}
//속한 노래가 많이 재생된 장르를 먼저 수록합니다.
//장르 내에서 많이 재생된 노래를 먼저 수록합니다.
//장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> g;//장르
    map<string,vector<pair<int,int>>> m;
    
    for(int i=0;i<genres.size();i++){
        g[genres[i]] += plays[i];
        m[genres[i]].push_back({plays[i],i});
    }
    vector<pair<string,int>> v2(g.begin(),g.end());
    sort(v2.begin(),v2.end(),sorted2);
    
    for(int i=0;i<v2.size();i++){
        //iter->first
        vector<pair<int,int>> v(m[v2[i].first]);
        sort(v.begin(),v.end(),sorted);
        answer.push_back(v[0].second);
        if(v.size()>1){
            answer.push_back(v[1].second);
        }
    }
    
    
    return answer;
}