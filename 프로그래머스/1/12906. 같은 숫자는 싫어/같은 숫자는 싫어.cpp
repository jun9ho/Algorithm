#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    st.push(arr[0]);
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(st.top()==arr[i]) continue;
        else{
            st.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    

    return answer;
}