#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    map<int,int> left;
    map<int,int> right;
    priority_queue<int,vector<int>,greater<int>> lpq;
    priority_queue<int,vector<int>,greater<int>> rpq;
    for(int i=1;i<a.size();i++){
        right[a[i]]++;
        rpq.push(a[i]);
    }
    //i=0 일떄
    answer++;
    left[a[0]]++;
    lpq.push(a[0]);
    for(int i=1;i<a.size()-1;i++){
        //a[i], lpq , rpq 비교해야돼
        right[a[i]]--;
        while(!right[rpq.top()]&& !rpq.empty()) rpq.pop();
        int k = 0;
        if(a[i]<lpq.top()) k++;
        if(a[i]<rpq.top()) k++;
        if(k>=1) answer++;
        lpq.push(a[i]);
        left[a[i]]++;
        
    }
    answer++;
    return answer;
}