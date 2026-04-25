#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i=0;i<operations.size();i++){
        string s = operations[i];
        stringstream ss(s);
        string a,b;
        ss>>a>>b;
        if(a=="I"){
            int k = stoi(b);
            dq.push_back(k);
            sort(dq.begin(),dq.end());
        }
        else{
            if(dq.size()==0) continue;
            if(b=="1"){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
            
        }
    }
    if(dq.size()==0) return {0,0};
    
    return {dq[dq.size()-1],dq[0]};
}