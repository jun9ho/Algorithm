#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //i번쨰부터 j번쨰 까지 자르고 정렬 k번쨰있는수
    for(int i=0;i<commands.size();i++){
        // commands[i][0] i번쨰부터
        // commands[i][1] j번쨰까지 정렬
        // commands[i][2] k번쨰 수
        vector<int> arr(array.begin()+commands[i][0]-1,array.begin()+commands[i][1]);
        sort(arr.begin(),arr.end());
        answer.push_back(arr[commands[i][2]-1]);
    }
    
    
    
    return answer;
}