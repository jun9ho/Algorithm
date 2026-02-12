#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    for(auto& c:str1){
        c = tolower(c);
        if(c<'a' || c>'z')c=',';
    }
    for(auto& c:str2){
        c = tolower(c);
        if(c<'a' || c>'z')c=',';
    }
    map<string,int>m1;// str1
    map<string,int>m2;// str2
    map<string,int>m3;// str1 + str2
    
    stringstream ss(str1);
    string token;
    while(getline(ss,token,',')){
        if(token.length()==0 || token.length()==1) continue;
        for(int i=0;i<token.length()-1;i++){
            string a ="";
            a+= token[i];
            a+= token[i+1];
            m1[a]++;
            m3[a]++;
        }
    }
    stringstream ss2(str2);
    string token2;
    while(getline(ss2,token2,',')){
        if(token2.length()==0 || token2.length()==1) continue;
        for(int i=0;i<token2.length()-1;i++){
            string a ="";
            a+= token2[i];
            a+= token2[i+1];
            m2[a]++;
            m3[a]++;
        }
    }
    //-> aa m1: 2 m2:3 m3:5
    //FRANCE FRENCH
    //m1: FR RA AN NC CE AA AA
    //m2: FR RE EN NC CH AA AA AA
    //m3: FR2 RA AN NC2 CE RE EN CH AA5 
    double a =0,b=0;
    for(auto iter = m3.begin();iter!=m3.end();iter++){
        a+=min(m1[iter->first],m2[iter->first]);
        b+=max(m1[iter->first],m2[iter->first]);
    }
    if(b==0) return 65536;
    
    answer = (int)(65536 / b * a);
    return answer;
}