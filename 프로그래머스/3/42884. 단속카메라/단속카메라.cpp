#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    int cur = routes[0][1];
    for(auto route:routes){
        //route[0],route[1]
        if(cur<route[0]){
            answer++;
            cur=route[1];
        }
        else{
            cur=min(route[1],cur);
        }
    }
    return answer;
}