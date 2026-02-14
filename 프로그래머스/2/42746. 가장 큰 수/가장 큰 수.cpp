#include <bits/stdc++.h>

using namespace std;


bool comp(int a,int b){
    
    string sa = to_string(a);
    string sb = to_string(b);
    
    return sa+sb>sb+sa;
}

string solution(vector<int> numbers) {
    string answer="";
    sort(numbers.begin(),numbers.end(),comp);
    for(int i=0;i<numbers.size();i++){
        answer+=(to_string(numbers[i]));
    }
    while(answer[0]=='0'){
        answer.erase(answer.begin());
    }
    if(answer.length()==0) return "0";
    return answer;
}