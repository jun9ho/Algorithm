#include <bits/stdc++.h>

using namespace std;

struct Node{
    int index;
    int value;
    
    bool operator<(const Node& other)const{
        return value<other.value;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<Node>q;
    priority_queue<Node>pq;
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]});
        pq.push({i,priorities[i]});
    }
    while(!q.empty()){
        int idx = q.front().index;
        int prior = q.front().value;
        q.pop();
        
        if(pq.top().value == prior){
            if(location==idx)
                return answer;
            else{
                pq.pop();
                answer++;
            }
        }
        else{
            q.push({idx,prior});
        }
    }
    
    
    
    return answer;
}