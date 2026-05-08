#include <bits/stdc++.h>

using namespace std;


vector<int> bfs(vector<vector<pair<int,int>>> v,int n, int s){
    
    queue<pair<int,int>> q; //node, dist
    vector<int> dist(n,INT_MAX);
    
    q.push({s,0});
    dist[s]=0;
    
    while(!q.empty()){
        int cur = q.front().first;
        int curd = q.front().second;
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nd = curd + v[cur][i].second;
            if(nd>=dist[next]) continue;
            q.push({next,nd});
            dist[next]= nd;
        }    
    }
    
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<pair<int,int>>> v(n);
    for(int i=0;i<fares.size();i++){
        v[fares[i][0]-1].push_back({fares[i][1]-1,fares[i][2]});
        v[fares[i][1]-1].push_back({fares[i][0]-1,fares[i][2]});
    }
    
    vector<int> ds,da,db;
    s--;a--;b--;
    ds = bfs(v,n,s);
    da = bfs(v,n,a);
    db = bfs(v,n,b);
    int dA =0;
    answer = INT_MAX;
    for(int i=0;i<n;i++){
        if(ds[i]==INT_MAX || da[i]==INT_MAX || db[i]==INT_MAX ) continue;
        dA = ds[i]+da[i]+db[i];
        if(dA<answer){
            answer=dA;
        }
    }
    
    
    return answer;
}