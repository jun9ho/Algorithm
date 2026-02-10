#include <bits/stdc++.h>
using namespace std;

//총 N 마리의 폰켓몬 중에서 N/2마리를 가져가도 좋다
// 폰켓몬은 종류에 따라 번호를 붙여 구분 -> 같은 종류의 폰켓몬은 같은 번호
// 
int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    if(nums.size()/2 > m.size()){
        answer = m.size();
    }
    else answer = nums.size()/2;
    
    return answer;
}