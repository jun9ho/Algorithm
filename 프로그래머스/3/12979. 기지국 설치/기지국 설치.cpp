#include <bits/stdc++.h>
using namespace std;


int cal(int len, int width){
    int a = len/width;
    int b = len%width;
    if(b==0) return a;
    else return a+1;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    //다음 것의 왼쪽이 이전것의 오른쪽보다 작다면 다음 오른쪽을 갱신하고 이런식으로
    //크다면 그것의 길이를 그전까지의 길이를 계산하는거임 -> cal
    
    int left =0, right =0;
    
    for(auto station:stations){
        station--;
        right = station - w - 1;
        if(left<=right){//겹쳐있지않다면
            answer += cal(right-left+1,2*w+1);
        }
        left = station + w +1;
    }
    if(left<n){
        right = n-1;
        answer += cal(right-left+1,2*w+1);
    }
    
    return answer;
}