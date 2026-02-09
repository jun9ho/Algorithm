#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<sizes.size();i++){
        v1.push_back(max(sizes[i][0],sizes[i][1]));
        v2.push_back(min(sizes[i][0],sizes[i][1]));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    answer = v1[sizes.size()-1] * v2[sizes.size()-1];
    
    return answer;
}