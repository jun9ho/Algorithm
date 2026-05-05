#include <bits/stdc++.h>

using namespace std;
string to_time(int a){
    string k;
    int b = a/60;
    int c = a%60;
    if(b<10){
        k+="0";
        k+=to_string(b);
    }
    else k+=to_string(b);
    k+=":";
    if(c<10){
        k+="0";
        k+=to_string(c);
    }
    else k+=to_string(c);
    
    return k;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    //09:00 부터 n번 t분 간격으로 m명 태운다.
    //가장 마지막버스를 마지막 번호에 타야한다.
    //
    sort(timetable.begin(),timetable.end());
    
    //bus시간 int로바꿈
    vector<int> bus;
    for(int i=0;i<n;i++){
        bus.push_back(540+i*t);
    }
    //timetable을 int로 바꿈
    vector<int> v(timetable.size(),0);
    for(int i=0;i<timetable.size();i++){
        stringstream ss(timetable[i]);
        int time=0;
        string token;
        getline(ss,token,':');
        time += stoi(token)*60;
        getline(ss,token,':');
        time += stoi(token);
        v[i]=time;
    }
    map<int,int> ma1;
    map<int,vector<int>> ma2;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<bus.size();j++){
            //bus[j]
            //v[i]
            if(bus[j]>=v[i]){
                if(ma1[bus[j]]<m){
                    ma1[bus[j]]++;
                    ma2[bus[j]].push_back(v[i]);
                    break;
                }
            }
        }   
    }
    if(ma1[bus[bus.size()-1]]<m){
        return to_time(bus[bus.size()-1]);
    }
    else{
        return to_time(ma2[bus[bus.size()-1]][m-1]-1);
    }
    
    
    return answer;
}