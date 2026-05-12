#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int l = w*2+1;
    int cur=1;
    vector<int> v;
    for(auto station:stations){
        int a = station-w-1;
        int b = station+w+1;
        int len = a-cur+1;
        if(len>0) {
            answer+=len/l;
            if(len%l!=0)answer++;
        }
        cur=b;
    }
    
    if(n-cur>=0){
        answer+=(n-cur+1)/l;
        if((n-cur+1)%l!=0) answer++;
    }
 
    
    return answer;
}