#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string token;
    vector<int> v;
    while(getline(ss,token,' ')){
        v.push_back(stoi(token));
    }
    sort(v.begin(),v.end());
    answer+=to_string(v[0]);
    answer+=' ';
    answer+=to_string(v[v.size()-1]);
    
    return answer;
}