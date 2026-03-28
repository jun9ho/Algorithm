#include <bits/stdc++.h>

using namespace std;


vector<int> bfs(int start, vector<vector<pair<int,int>>> v,int n){
    queue<pair<int,int>> q;
    vector<int> d(n,99999999);
    
    q.push({start-1,0});
    d[start-1]=0;
    while(!q.empty()){
        int cur = q.front().first;
        int curDist = q.front().second;
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int dist = v[cur][i].second;
            if(dist+curDist>=d[next]) continue;
            q.push({next,curDist+dist});
            d[next] = curDist+dist;
        }
        
    }
    
    return d;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<pair<int,int>>> v(n);
    for(int i=0;i<fares.size();i++){
        v[fares[i][0]-1].push_back({fares[i][1]-1,fares[i][2]});
        v[fares[i][1]-1].push_back({fares[i][0]-1,fares[i][2]});
    }
    
    vector<int> ms = bfs(s,v,n);
    vector<int> ma = bfs(a,v,n);
    vector<int> mb = bfs(b,v,n);
    vector<int> m(n,-1);
    int sum = 99999999;
    for(int i=0;i<n;i++){
        if(ms[i]==99999999 || ma[i]==99999999 || mb[i]==99999999) continue;
        m[i] = ms[i] + ma[i] + mb[i];
        sum = min(sum,m[i]);
    }
    
    return sum;
}