#include <bits/stdc++.h>

using namespace std;

int answer = 0;
void dfs(int idx,int sum, vector<int>& numbers, int target){
    
    if(idx==(numbers.size()-1)){
        if(sum==target) answer++;
        return;
    }
    
    dfs(idx+1,sum+numbers[idx],numbers,target);
    dfs(idx+1,sum-numbers[idx],numbers,target);
    
    return;
}

int solution(vector<int> numbers, int target) {
    numbers.push_back(0);
    dfs(0,0, numbers,target);
    
    return answer;
}