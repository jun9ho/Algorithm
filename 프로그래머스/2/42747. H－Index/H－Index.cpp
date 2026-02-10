#include <bits/stdc++.h>

using namespace std;

//발표한 논문 n편중 h번 이상 인용된 논문이h편 이상이고 나머지 논문이 h번 이하 인용되었다면
//h의 최댓값이 이 과학자의 H-Index


int solution(vector<int> citations) {
    int answer = 0;
    int hIndex = citations.size();
    sort(citations.begin(),citations.end(),greater<>());
    while(hIndex>=0){
        int cit = 0;
        int ncit = 0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=hIndex) cit++;
            else break;
        }
        if(cit>=hIndex) return hIndex;
        hIndex--;
    }
    
    return hIndex;
}