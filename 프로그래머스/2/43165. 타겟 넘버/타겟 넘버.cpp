#include <bits/stdc++.h>

using namespace std;

int cnt =0;
void dfs(int idx, vector<int>& numbers, int& target,int answer){
    
    if(idx ==numbers.size()){
        if(answer==target) cnt++;
        return;
    }
    
    dfs(idx+1,numbers,target,answer+numbers[idx]);
    dfs(idx+1,numbers,target,answer-numbers[idx]);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0,numbers,target,0);
    answer=cnt;
    
    
    return answer;
}