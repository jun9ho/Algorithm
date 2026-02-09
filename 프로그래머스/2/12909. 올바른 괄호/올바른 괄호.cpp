#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    st.push(s[0]);
    if(s[0]==')') return false;
    
    for(int i=1;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            else{
                st.pop();
            }
        }
    }
    if(st.size()!=0) return false;
    else return true;
}