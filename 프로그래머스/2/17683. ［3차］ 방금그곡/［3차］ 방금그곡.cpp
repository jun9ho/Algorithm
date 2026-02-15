#include <bits/stdc++.h>

using namespace std;
//네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개
// A B C D E F G
// A# C# D# F# G# -> H I J K L
//음 변환 -> m과 musicinfos[3]
//각각 musicinfos[1]-musicinfos[0] 만큼의 악보 만들기
//악보에서 find(m)
//다 체크해서 여러개 있으면 조건에 따라서 반환

string change(string a){
    string s="";
    for(int i=0;i<a.length();i++){
        if(a[i]=='#'){
            if(a[i-1]=='A'){
                s[s.size()-1]='H';
            }
            if(a[i-1]=='C'){
                s[s.size()-1]='I';
            }
            if(a[i-1]=='D'){
                s[s.size()-1]='J';
            }
            if(a[i-1]=='F'){
                s[s.size()-1]='K';
            }
            if(a[i-1]=='G'){
                s[s.size()-1]='L';
            }
            continue;
        }
        s+=a[i];
    }
    return s;
}

bool comp(pair<int,string> a,pair<int,string> b){
    
    return a.first>b.first;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m = change(m);
    vector<pair<int,string>> v;
    for(int i=0;i<musicinfos.size();i++){
        stringstream ss(musicinfos[i]);
        string token;
        getline(ss,token,',');
        int a1 = stoi(token.substr(0,2))*60 + stoi(token.substr(3,2));
        getline(ss,token,',');
        int b1 = stoi(token.substr(0,2))*60 + stoi(token.substr(3,2));
        int time = b1 - a1;
        getline(ss,token,',');
        string title = token;
        getline(ss,token,',');
        string music = token;
        music = change(music);
        //time,title,music
        string str ="";
        for(int i=0;i<time;i++){
            str+=music[i%music.size()];
        }
        if(str.find(m)!=string::npos){
            v.push_back({time,title});
        }
    }
    
    if(v.size()==0) return "(None)";
    else if(v.size()==1) return v[0].second;
    else{
        // 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다.
        // 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
        stable_sort(v.begin(),v.end(),comp);
        return v[0].second;
    }
}