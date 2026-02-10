#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int len = arr1.size();
    for(int i=0;i<len;i++){
        int num1 = arr1[i];
        int num2 = arr2[i];
        int num = num1 | num2;
        string str = "";
        for(int j=0;j<n;j++){
            if(num>>j & 1 == 1) str+="#";
            else str+=" ";
        }
        reverse(str.begin(),str.end());
        answer.push_back(str);
        
    }
    
    return answer;
}