#include <bits/stdc++.h>

using namespace std;

//progresses: 먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열
//speeds: 각 작업의 개발 속도가 적힌 정수 배열 
//각 배포마다 몇 개의 기능이 배포되는지를 return 

// [93, 30, 55]	[1, 30, 5]
// [7,4,9];
// [5,10,1,1,20,1];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;//소요 일수
    for(int i=0;i<progresses.size();i++){
        int a = 100-progresses[i];
        int b = speeds[i];
        if(a%b==0) v.push_back(a/b);
        else v.push_back((a/b)+1);
    }
    int cur = v[0];
    int cnt = 1;
    for(int i=1;i<v.size();i++){
        if(cur>=v[i]){
            cnt++;
        }
        else{
            cur = v[i];
            answer.push_back(cnt);
            cnt=1;
        }
    }
    if(cnt!=0) answer.push_back(cnt);
    return answer;
}