#include <bits/stdc++.h>

using namespace std;

// A0 B1 C2 D3 E4 F5 G6 H7 I8 J9 K10 L11 M12 N13 O12 P11 Q10 R9 S8 T7 U6 V5 W4 X3 Y2 Z1
//

int solution(string name) {
    int answer = 0;
    unordered_map<char,int> m;
    for(int i=0;i<13;i++){
        m['A'+i]=i;
        m['Z'-i]=i+1;
    }
    for(int i=0; i<name.length();i++){
        answer+=m[name[i]];
    }
    int n = name.length();
    //"DASDLKAAAAAAABAAAAAAAASDDSS"
    int move = n - 1;
    for (int i=0; i <n;i++) {
        int j = i+1;
        while (j<n && name[j] == 'A') j++;
        move = min(move, 2 * i + (n - j));
        move = min(move, i + 2 * (n - j));
    }
    answer+=move;
    return answer;
}