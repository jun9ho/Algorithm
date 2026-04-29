#include <bits/stdc++.h>

using namespace std;


bool sort1(pair<string,int> a, pair<string,int> b){
    
    return a.second>b.second;
}

bool sort2(pair<int,int> a, pair<int,int>b){
    
    
    if(a.second==b.second){
        return a.first<b.first;
    }
    
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //속한 노래가 많이 재생된 장르를 먼저 수록
    //-> 장르별로 노래 수 구하기
    //장르 내에서 많이 재생된 노래를 먼저 수록
    //-> 각 장르마다 어떤 노래가 있는지 체크 (몇번)
    //장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
    int n = genres.size();
    
    map<string,int> m1;//장르별 총 노래수
    //장르 하나에 여러 노래,고유번호 짝이있어야돼
    map<string,vector<pair<int,int>>> m2;
    
    
    for(int i=0;i<n;i++){
        string genre = genres[i];
        m1[genre]+=plays[i];
        m2[genre].push_back({i,plays[i]});         
    }
    int maxx = -1;
    vector<pair<string,int>> v1(m1.begin(),m1.end());
    
    sort(v1.begin(),v1.end(),sort1);
    for(auto iter=m2.begin();iter!=m2.end();iter++){
        sort(iter->second.begin(),iter->second.end(),sort2);
    }
    
    for(int i=0;i<v1.size();i++){
        string a = v1[i].first;
        answer.push_back(m2[a][0].first);
        if(m2[a].size()>1) answer.push_back(m2[a][1].first);
    }
    
    
    return answer;
}