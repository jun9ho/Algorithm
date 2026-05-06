#include <bits/stdc++.h>

using namespace std;

bool sorted(vector<int> a, vector<int> b){
    
    if(a[0]==b[0]) return a[1]<b[1];
    
    return a[0]>b[0];
}


int solution(vector<vector<int>> scores) {
    int answer = 1;
    pair<int,int> wanho = {scores[0][0],scores[0][1]};
    sort(scores.begin(),scores.end(),sorted);
    
    int maxPeer = 0;
    for(auto score : scores){
        if(score[1]<maxPeer){
            if(score[0]==wanho.first && score[1]==wanho.second) return -1;
        }
        else {
            if(score[0]+score[1] > wanho.first + wanho.second){
                answer++;
            }

            maxPeer = max(maxPeer, score[1]);
        }
        
    }
    
    
    return answer;
}