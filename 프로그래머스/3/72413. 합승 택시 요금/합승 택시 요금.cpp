#include <bits/stdc++.h>
using namespace std;
struct Node{
    long long idx;
    long long dist;
    bool operator<(const Node& other)const{
        return dist>other.dist;
    }
};
static const long long INF = (long long)4e15;

vector<long long> bfs(int n,int start,vector<pair<int,int>> v[]){
    priority_queue<Node> q;
    vector<long long> dist(n,INF);
    dist[start] = 0;
    q.push({start,0});
    while(!q.empty()){
        long long cur = q.top().idx;
        long long fee = q.top().dist;
        q.pop();
        if(fee>dist[cur]) continue;
        
        for(int i=0;i<v[cur].size();i++){
            if(dist[v[cur][i].first]<=fee+v[cur][i].second) continue;
            dist[v[cur][i].first] = fee+v[cur][i].second;
            q.push({v[cur][i].first,fee+v[cur][i].second});
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int size = fares.size();
    vector<pair<int,int>> v[n]; // v[a] 에 {다음 index b, 요금}
    for(int i=0;i<size;i++){
        v[fares[i][0]-1].push_back({fares[i][1]-1,fares[i][2]});
        v[fares[i][1]-1].push_back({fares[i][0]-1,fares[i][2]});
    }
    
    //한 지점까지 bfs
    //그 지점에서 각 지점 까지 bfs 두번
    //합산한 결과
    vector<long long> dS = bfs(n, s-1, v);
    vector<long long> dA = bfs(n, a-1, v);
    vector<long long> dB = bfs(n, b-1, v);

    
    long long ans = INF;
    for (int k = 0; k < n; ++k) {
        if (dS[k] == INF || dA[k] == INF || dB[k] == INF) continue; 
        long long cost = dS[k] + dA[k] + dB[k];
        if (cost < ans) ans = cost;
    }
    return (int)ans; 
}