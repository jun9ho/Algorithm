#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    multiset<int> ms;
    for(int i=0;i<k;i++){
        ms.insert(stones[i]);
    }
    answer= *ms.rbegin();
    for(int i=k;i<stones.size();i++){
        ms.erase(ms.find(stones[i-k]));
        ms.insert(stones[i]);
        answer= min(*ms.rbegin(),answer);
    }
    
    return answer;
}