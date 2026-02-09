#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<>());
    int i=0;
    int j=people.size()-1;
    while(i<=j){
        //큰사람 먼저 태워
        if(people[i]+people[j]<=limit){
            i++;
            j--;
        }
        else{
            i++;
        }
        answer++;
        
    }
    
    return answer;
}