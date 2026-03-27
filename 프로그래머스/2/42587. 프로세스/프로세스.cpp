#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int,int>> q1;
    priority_queue<int> q2;
    for(int i=0;i<priorities.size();i++){
        q1.push({i,priorities[i]});
        q2.push(priorities[i]);
    }
    while(!q1.empty()){
        int loc = q1.front().first;
        int n = q1.front().second;
        q1.pop();
        if(n==q2.top()){
            if(loc== location){
                return answer;
            }
            q2.pop();
            answer++;
        }
        else{
            q1.push({loc,n});
        }

    }
    
    return answer;
}