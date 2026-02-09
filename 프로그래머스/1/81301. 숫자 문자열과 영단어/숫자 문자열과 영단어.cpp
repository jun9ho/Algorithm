#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str = "";
    map<string,int> m;
    m["zero"]=0;m["one"]=1;m["two"]=2;
    m["three"]=3;m["four"]=4;m["five"]=5;
    m["six"]=6;m["seven"]=7;m["eight"]=8;
    m["nine"]=9;
    string st = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') str.push_back(s[i]);
        else{
            st+=s[i];
            if(m[st]>0){
                str+=to_string(m[st]);
                st="";
            }
            if(st=="zero"){
                str+="0";
                st="";
            }
        }
    }
    
    
    return stoi(str);
}