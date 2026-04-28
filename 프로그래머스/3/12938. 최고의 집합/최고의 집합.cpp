#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n>=2 && s==1) return {-1};
    if(n>s) return {-1};
    
    int a = s/n;
    int b = s%n;
    if(b==0){
        for(int i=0;i<n;i++) answer.push_back(a);
    }
    else{
        for(int i=0;i<n;i++) answer.push_back(a);
        for(int i=0;i<b;i++) answer[i]++;
    }
    sort(answer.begin(),answer.end());
    
    
    return answer;
}