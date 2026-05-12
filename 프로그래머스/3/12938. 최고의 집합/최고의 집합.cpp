#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    if(s/n==0) return{-1};

    vector<int> answer;
    int a = s/n;
    int b=  s%n;
    int k = n-b;
    for(int i=0;i<k;i++){
        answer.push_back(a);
    }
    for(int i=0;i<b;i++){
        answer.push_back(a+1);
    }
    
    
    
    return answer;
}