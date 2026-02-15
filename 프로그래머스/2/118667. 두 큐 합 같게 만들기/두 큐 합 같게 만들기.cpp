#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long long sum=0,sum1 = 0,sum2 =0;
    queue<int> q1;
    queue<int> q2;
    for(int i=0;i<queue1.size();i++){
        sum1 += queue1[i];
        sum += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i=0;i<queue2.size();i++){
        sum2 += queue2[i];
        sum += queue2[i];
        q2.push(queue2[i]);
    }
    if(sum%2!=0) return -1;
    sum/=2;
    int cnt=0;
    while(1){
        if(sum1>sum2){
            q2.push(q1.front());
            sum1-=(q1.front());
            sum2+=(q1.front());
            q1.pop();
            cnt++;
        }
        else if(sum2>sum1){
            q1.push(q2.front());
            sum2-=(q2.front());
            sum1+=(q2.front());
            q2.pop();
            cnt++;
        }
        else if(sum1==sum2){
            return cnt;
        }
        if(cnt == 300000) return -1;
    }
    
    
    
    return answer;
}