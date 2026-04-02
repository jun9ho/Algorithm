#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    
    //A0 B1 C2 D3 E4 F5 G6 H7 I8 J9 K10 L11 M12 N13 O12 P11 Q10 R9 S8 T7 U6 V5 W4 X3 Y2 Z1
    map<char,int> m;
    for(int i=0;i<26;i++){
        m['A'+i]=min(i,26-i);
    }
    for(int i=0;i<name.size();i++){
        answer+=m[name[i]];
    }
    if(answer==0) return 0;
    if(size==1){
        return answer;
    }
    int k = size-1;
    for(int i=0;i<size;i++){
        int j = i+1;
        while(j<size && name[j]=='A')j++;
        int a = i*2 + size-j;
        int b = i + (size-j)*2;
        k = min(k,min(a,b));
    }
    return answer+k;
}