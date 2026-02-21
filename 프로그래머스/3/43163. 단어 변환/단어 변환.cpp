#include <bits/stdc++.h>

using namespace std;

int bfs(int targetIndex,vector<int> v[],int n){
    
    queue<pair<int,int>> q; // index, dist
    q.push({0,0});
    vector<bool> vis(n,false);
    
    while(!q.empty()){
        int curIndex = q.front().first;
        int curDist = q.front().second;
        q.pop();
        if(curIndex==targetIndex){
            return curDist;
        }
        for(int i=0;i<v[curIndex].size();i++){

            q.push({v[curIndex][i],curDist+1});
        }
        
    }
    
    
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    auto iter = find(words.begin(),words.end(),target);
    if(iter==words.end() ) return 0;
    words.insert(words.begin(),begin);
    vector<int> v[words.size()];
    
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            if(words[i]==words[j]) continue;
            int cnt =0;
            for(int k=0;k<words[i].length();k++){
                if(words[i][k]==words[j][k]) cnt++;
            }
            if(cnt == words[i].length()-1){
                v[i].push_back(j);
            }
        }
    }
    
    auto iter2 = find(words.begin(),words.end(),target);
    return bfs(iter2-words.begin(),v,words.size());
    
    
    
    
    return answer;
}